// You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.
// The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. 
// xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.
// You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.
// Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb

// Input: bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
// Output: 5
// Explanation:
// The best bomb to detonate is bomb 0 because:
// - Bomb 0 detonates bombs 1 and 2. The red circle denotes the range of bomb 0.
// - Bomb 2 detonates bomb 3. The blue circle denotes the range of bomb 2.
// - Bomb 3 detonates bomb 4. The green circle denotes the range of bomb 3.
// Thus all 5 bombs are detonated.

#include<iostream>
#include<unordered_map>
#include<vector>

class Solution {
    public:
        int maximumDetonation(std::vector<std::vector<int>>& bombs) {
            // a graph traversal , why graph?
            // as u can see , we need to see if we detonate a bomb , what more
            // adjacent bombs will also be detonated , so its like neighbor of the
            // detonated bombs that will be detonated in chain its a directed edge
            // graph because bomb1 can detonate bomb2 but bomb2 can or cannot
            // detonate bomb1
    
            std::unordered_map<int, std::vector<int>> AdjList;
            // how will we know which bomb will detonate other bomb
            // if we find distance between the centers of the bombs , we can check
            // which bomb blast radius is greater or equal to the distance between 2
            // bombs , the more the radius the more nodes it can do detonation
            // chaining
    
            // compute the distance using formula , d = sqrt((x1-x2)^2 + (y1-y2)^2)
            for (int i = 0; i < bombs.size(); i++) {
                for (int j = i + 1; j < bombs.size(); j++) {
                    int x1 = bombs[i][0];
                    int y1 = bombs[i][1];
                    long long r1 = bombs[i][2];
    
                    int x2 = bombs[j][0];
                    int y2 = bombs[j][1];
                    long long r2 = bombs[j][2];
                    
                    long long dist_x = x1-x2;
                    long long dist_y = y1-y2;
    
                    if (dist_x*dist_x + dist_y*dist_y <= r1*r1)
                        AdjList[i].push_back(j);
                    if (dist_x*dist_x + dist_y*dist_y <= r2*r2)
                        AdjList[j].push_back(i);
                }
            }
    
            auto dfs = [&](auto&& self, int idx,std::vector<bool>& visited) -> int {
                visited[idx]= true;
                int count = 1;
                for (auto& ngbr : AdjList[idx]) {
                    if(!visited[ngbr]){
                    count += self(self, ngbr, visited);
                    }
                }
                return count;
            };
    
            int res = 0;
            for (int i = 0; i < bombs.size(); i++) {
                std::vector<bool>visited(bombs.size(),false);
                res = std::max(res, dfs(dfs, i,visited));
            }
            return res;
        }
    };

int main(){
    Solution sol1;
    std::vector<std::vector<int>>bombs = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
    std::cout<<"Maximum number of detonation : "<<sol1.maximumDetonation(bombs);
    return 0;
}