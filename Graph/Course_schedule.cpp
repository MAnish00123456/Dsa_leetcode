// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    vector<vector<int>>AdjList;
    bool isCycle(int node ,vector<bool>& visited , vector<bool>&recPath){
        visited[node] = true;
        recPath[node] = true;

        for(int ngbr :  AdjList[node]){
            if(!visited[ngbr]){
                if(isCycle(ngbr,visited,recPath)){
                    return true;
                }
            }else if(recPath[ngbr]){
                return true;
            }
        }
        recPath[node] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //prerequisites defines before taking a course u need to select another course given in form of [a,b]
        //if we draw these requisites , we get a graph like diagram
        //we need to determine if we are able to finish up all courses , means a linear ordering of courses , which can be obtained using topological sort
        //topo sort is basically on DAG , so in this question its simply checking if we get a topo sort or not
        //we get a topo sort if its a DAG so return true in that case , but if we dont have a DAG means we have a cycle in our graph we return false
        //so its simply check if the directed graph have a cyclr or not
        AdjList.resize(numCourses);
        
        for(auto& edge : prerequisites){
            AdjList[edge[1]].push_back(edge[0]);
        }
        vector<bool>visited(numCourses,false);
        vector<bool>recPath(numCourses,false);
        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i]){
               if(isCycle(i,visited,recPath)){
                return false;
               }
            }
        }

        return true;
    }
};

int main(){
    Solution sol1;

    int numCourses = 2;
    vector<vector<int>>prerequisites = {{1,0},{0,1}};

    if(sol1.canFinish(numCourses,prerequisites))cout<<"True";
    else cout<<"False";
    return 0;
}