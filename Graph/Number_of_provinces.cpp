// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void dfs(int i ,vector<bool>&visited , vector<vector<int>>&AdjList){
        
        if(visited[i])return;

        visited[i] = true;
        for(auto& ngbr: AdjList[i]){
            dfs(ngbr,visited,AdjList);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        vector<bool>visited(m,false);
        vector<vector<int>>AdjList(m);
        
        for(int i = 0 ; i < m ; i++){
            for(int ngbr = 0 ; ngbr < isConnected[i].size() ; ngbr++){
                if(ngbr == i)continue;
                if(isConnected[i][ngbr] == 1){
                    AdjList[i].push_back(ngbr);
                }
            }
        }

        int count = 0;

        for(int i = 0 ; i < m ; i++){
                if(!visited[i]){
                    dfs(i,visited,AdjList);
                    count++;
                }
        }
        return count;
    }
};

int main(){
    vector<vector<int>>isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    Solution sol1;
    cout<<sol1.findCircleNum(isConnected);
    return 0;
}