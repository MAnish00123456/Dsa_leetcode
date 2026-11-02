// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi 
// is the target node, and wi is the time it takes for a signal to travel from source to target.
// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    //djikstra's algorithm , find shortest path from souce node to each node , and then find if we can reach every node from souce node or not, if node return -1 or else return maximum time we had to reach the last node
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>AdjList(n+1);
        // n= n+1;
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;

        for(auto& time : times){
            int u = time[0];
            int v = time[1];
            int dt = time[2];

            AdjList[u].push_back({dt,v});
        }

        //min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});//dist,src

        while(!pq.empty()){
            auto p  = pq.top();
            pq.pop();
            int d = p.first;
            int u = p.second;

            if(d > dist[u])continue;
            for(auto& ngbr : AdjList[u]){
                int dt = ngbr.first;
                int v = ngbr.second;

                if(dist[u]+ dt < dist[v]){
                    dist[v] = dist[u] + dt;
                    pq.push({dist[v],v});
                }
            }
        }
        int mdist = INT_MIN;
        for(int i = 1 ; i <= n ; i++){
            if(dist[i] == INT_MAX)return -1;
            if(dist[i] > mdist){
                mdist = dist[i];
            }
        }
        return mdist;
    }
};

int main(){
    vector<vector<int>>times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4 , k =2;
    Solution sol1;
    cout<<sol1.networkDelayTime(times,n,k);

    return 0;
}

