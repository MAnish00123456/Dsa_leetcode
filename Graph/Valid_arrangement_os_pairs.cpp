// You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti.

// Return any valid arrangement of pairs.

// Note: The inputs will be generated such that there exists a valid arrangement of pairs.

// Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
// Output: [[11,9],[9,4],[4,5],[5,1]]
// Explanation:
// This is a valid arrangement since endi-1 always equals starti.
// end0 = 9 == 9 = start1 
// end1 = 4 == 4 = start2
// end2 = 5 == 5 = start3

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
    //solve Reconstuct itinerary to understand about  this question , it also uses hierHolzer's algorithm
    //just the tweak is this in this question we need to find our starting vertex ourself , which we can find from either of two cases:-
        //1.  if the graph has complete eulerian cycle means a perfect loop , so for each  vertex m , its indegree == outdegree
        //2. if the graph is semi eulerian cycle means no loop , so we find a vertex m whose outdegree - indegree == 1,
            // that will act as our starting vertex
    private:
    unordered_map<int,vector<int>>AdjList;
    unordered_map<int,int>inDeg,outDeg;//indeg,outdeg


    vector<vector<int>>Ans;

    void dfs(int stNode,int pNode){

        while(!AdjList[stNode].empty()){
            int toNode = AdjList[stNode].back();
            AdjList[stNode].pop_back();//consume this edge so we never visit it again
            dfs(toNode,stNode);
        }
        if(pNode != -1){
        Ans.push_back({pNode,stNode});
        }

    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        for(auto& pair : pairs){
            AdjList[pair[0]].push_back(pair[1]);
            outDeg[pair[0]]++;
            inDeg[pair[1]]++;
        }

        int stVertex = pairs[0][0];
        
for(auto& [node, out] : outDeg){
    if(out - inDeg[node] == 1){
        stVertex = node;
        break;
    }
}
        
        //HierHolzer algo
        dfs(stVertex,-1);
        reverse(begin(Ans),end(Ans));
        return Ans;
    }
};

int main(){
    Solution sol1;
    vector<vector<int>>pairs =  {{5,1},{4,5},{11,9},{9,4}};
    vector<vector<int>>ans = sol1.validArrangement(pairs);
    for(auto it : ans){
        for(int v : it){
            cout<<v<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
