// There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

// When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

// Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

// Input: rooms = [[1],[2],[3],[]]
// Output: true
// Explanation: 
// We visit room 0 and pick up key 1.
// We then visit room 1 and pick up key 2.
// We then visit room 2 and pick up key 3.
// We then visit room 3.
// Since we were able to visit every room, we return true.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void dfs(int st , vector<vector<int>>&rooms , vector<int>&Vis){
        Vis[st] = 1;

        for(auto ngbr : rooms[st]){
            if(Vis[ngbr] == 0){
                dfs(ngbr,rooms,Vis);
            }
        }

    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>Vis(n,0);
    //a simple dfs , starting from '0' , if any room we cant visit starting from room '0' then its false
        dfs(0,rooms,Vis);
        for(int i = 0 ;  i < n ; i++){
            if(Vis[i] == 0)return false;
        }
        return true;
    }
};

int main(){
    vector<vector<int>> rooms = {{1},{2},{3},{}};
    Solution sol1;
    cout<<(sol1.canVisitAllRooms(rooms) ? "true" : "false");
    return 0;
}