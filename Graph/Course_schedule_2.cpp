// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

#include<iostream>
#include<vector>
using namespace std;
#include<queue>
// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].


class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            //similar as Course Schedule , but in this , we need to find the course taking order if we are able to select all courses 
            //used kahn's algorithm to solve this (basically find topo sort)
            vector<vector<int>>AdjList(numCourses);
    
            for(auto& edge : prerequisites){
                AdjList[edge[1]].push_back(edge[0]);
            }
    
            vector<int>Order;
            queue<int>q;
            vector<int>indegree(numCourses);
    
            for(int i = 0 ; i < numCourses ; i++){
                for(int ngbr : AdjList[i]){
                    indegree[ngbr]++;
                }
            }
    
            for(int i = 0 ; i < numCourses ; i++){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
    
            while(!q.empty()){
                int node = q.front();
                q.pop();
    
                Order.push_back(node);
    
                for(int ngbr : AdjList[node]){
                    indegree[ngbr]--;
                    if(indegree[ngbr] == 0){
                        q.push(ngbr);
                    }
                }
    
            }
    
        return Order.size() == numCourses?Order:vector<int>{};
        }
    };

int main(){
    int numCourses = 4;
    vector<vector<int>>prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    Solution sol1;
    vector<int>Ans = sol1.findOrder(numCourses,prerequisites);
    for(auto it : Ans)cout<<it<<" ";
    return 0;
}