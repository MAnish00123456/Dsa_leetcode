// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.


#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Normal shortest path:
//     "What is the cheapest way to reach this node?"
//
// Here:
//     "What is the cheapest way to reach this node
//      while respecting the maximum number of stops?"
//
// Therefore, every queue state carries BOTH:
//     1. current node
//     2. number of stops used
//     3. cost of that particular path
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // Adjacency list:
        // AdjList[u] contains {price, destination} for every flight
        // going from city u to another city.
        vector<pair<int,int>> AdjList[4];

        for(auto& flight : flights){
            int u = flight[0];
            int v = flight[1];
            int p = flight[2];

            AdjList[u].push_back({p, v});
        }

        // dist[i] = cheapest cost found so far to reach city i.
        //
        // Unlike normal Dijkstra, we ALSO have a restriction on
        // how many stops/flights we are allowed to use.
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // State stored in queue:
        // {stops, {current node, cost of this particular path}}
        //
        // We keep the path cost inside the queue because dist[node]
        // is a global value, while 'cost' represents the exact path
        // we are currently exploring.
        queue<pair<int,pair<int,int>>> pq;

        // Start at src with 0 flights taken and 0 cost.
        pq.push({0, {src, 0}});

        while(!pq.empty()){

            auto it = pq.front();
            pq.pop();

            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // We are allowed at most k stops.
            // Once this state has already used more than k stops,
            // we cannot explore any further from it.
            if(stop > k)
                continue;

            // Try taking one more flight from the current city.
            for(auto it : AdjList[node]){

                int cst = it.first;
                int nbr = it.second;

                // If taking this flight gives us a cheaper way to
                // reach nbr, and we have not exceeded the stop limit,
                // update its cheapest known cost.
                //
                // IMPORTANT:
                // Use 'cost', not dist[node].
                // 'cost' is the cost of THIS particular path/state.
                if(cost + cst < dist[nbr] && stop <= k){

                    dist[nbr] = cost + cst;

                    // Taking one more flight increases the number
                    // of stops/flights used by one.
                    pq.push({
                        stop + 1,
                        {nbr, dist[nbr]}
                    });
                }
            }
        }

        // Destination was never reached within the allowed limit.
        if(dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};

int main(){
    int n = 4;
    vector<vector<int>>flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0, dst = 3 , k = 1;

    Solution sol1;
    cout<<sol1.findCheapestPrice(n,flights,src,dst,k);
    return 0;
}