// You are given an m x n integer matrix grid and an array queries of size k.

// Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:

// If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
// Otherwise, you do not get any points, and you end this process.
// After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.

// Return the resulting array answer

// Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
// Output: [5,8,1]


#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>


class Solution {
    int m, n;

    // Cells that have already been completely processed/reached.
    // Once a cell becomes visited, it contributes to the answer
    // for every larger query as well.
    std::vector<std::vector<bool>> visited;

    /*
        Min-heap containing the current "frontier" of reachable cells.

        Each entry:
            {cell value, {row, col}}

        We always need the smallest-valued frontier cell first.

        Why?
        For a query = X, if the smallest frontier value >= X,
        then NO other frontier cell can be entered either.
    */
   std::priority_queue<
   std::pair<int, std::pair<int,int>>,
   std::vector<std::pair<int, std::pair<int,int>>>,
   std::greater<std::pair<int, std::pair<int,int>>>
    > pq;


    int maxPoints_bfs(std::vector<std::vector<int>>& grid, int num) {

        int points = 0;

        int rDir[4] = {-1, 1, 0, 0};
        int cDir[4] = {0, 0, -1, 1};

        /*
            Expand the already-reachable region.

            We only enter a cell when:
                cell value < current query

            Because pq always gives us the smallest frontier cell,
            once pq.top().first >= num, we can stop.

            IMPORTANT:
            This BFS state is NOT reset between queries.
            Larger queries continue from where smaller queries stopped.
        */
        while (!pq.empty() && pq.top().first < num) {

            auto [value, pos] = pq.top();
            pq.pop();

            auto [x, y] = pos;

            // A cell may have been inserted into the heap multiple
            // times through different neighbours, so ignore duplicates.
            if (visited[x][y])
                continue;

            // First time we process this cell, it becomes permanently
            // reachable and contributes one point.
            visited[x][y] = true;
            points++;

            // Add neighbours to the frontier.
            // They may or may not be reachable for the current query,
            // but they are candidates for future larger queries.
            for (int i = 0; i < 4; i++) {

                int nRow = x + rDir[i];
                int nCol = y + cDir[i];

                if (nRow >= 0 && nRow < m &&
                    nCol >= 0 && nCol < n &&
                    !visited[nRow][nCol]) {

                    pq.push({
                        grid[nRow][nCol],
                        {nRow, nCol}
                    });
                }
            }
        }

        // Number of NEW cells reached for this query.
        return points;
    }


public:
std::vector<int> maxPoints(std::vector<std::vector<int>>& grid,
    std::vector<int>& queries) {

        m = grid.size();
        n = grid[0].size();

        int k = queries.size();

        std::vector<int> answer(k, 0);

        visited.resize(m, std::vector<bool>(n, false));

        /*
            (0,0) is the starting cell.

            Initially it is the only cell known to us.
            It is placed in the min-heap rather than immediately
            marked visited because whether we can enter it depends
            on the query value.
        */
        pq.push({
            grid[0][0],
            {0, 0}
        });


        /*
            Queries must be processed in increasing order.

            Example:
                query = 3
                query = 7
                query = 10

            Anything reachable with query 3 will ALSO be reachable
            with 7 and 10.

            Therefore we can reuse all previous BFS work.
        */
       std::vector<std::pair<int,int>> sortedQueries;

        for (int i = 0; i < k; i++) {
            // Store {query value, original index}
            // so we can restore the original query order later.
            sortedQueries.push_back({queries[i], i});
        }

        std::sort(sortedQueries.begin(), sortedQueries.end());

        int points = 0;

        for (auto [query, index] : sortedQueries) {

            /*
                Continue expanding from the previous query.

                maxPoints_bfs() returns only the NEW cells discovered
                for this query, so accumulate them into the total.
            */
            points += maxPoints_bfs(grid, query);

            // Put the answer back at the query's original position.
            answer[index] = points;
        }

        return answer;
    }
};

int main(){
    std::vector<std::vector<int>>grid = {{1,2,3},{2,5,7},{3,5,1}};
    std::vector<int> queries = {5,6,2};
    Solution sol1;
    std::vector<int>Ans = sol1.maxPoints(grid,queries);
    for(int val : Ans){std::cout<<val<<" ";}
    return 0;
}
