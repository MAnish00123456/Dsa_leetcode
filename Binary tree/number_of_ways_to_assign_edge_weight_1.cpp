// There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
// Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
// The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
// Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd.
// Since the answer may be large, return it modulo 109 + 7.
// Note: Ignore all edges not in the path from node 1 to x.

// Input: edges = [[1,2],[1,3],[3,4],[3,5]]

// Output: 2

// Explanation:

// The maximum depth is 2, with nodes 4 and 5 at the same depth. Either node can be selected for processing.
// For example, the path from Node 1 to Node 4 consists of two edges (1 → 3 and 3 → 4).
// Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.

// class Solution {
//     #define ll long long
//     int mod = 1e9 + 7;
//     //fast exponentiation(binary) to get power of a to the b efficiently when b is very large in O(logb) time
//     ll BinaryExpo(ll base , ll expo){
//         if(expo == 0)return 1;

//         ll half = BinaryExpo(base,expo/2);

//         ll res = (half * half)%mod;

//         if(expo %  2 == 1){
//             res = (res * base)%mod;
//         }

//         return res;
//     }

//     //recursively get the maximum height in the undirected tree
//     int getMaxht(unordered_map<int,vector<int>>& adj , int node , int parent){
//         int mxHt = 0;
//     //O(n)
//         for(auto& neighbor : adj[node]){
//             if(neighbor == parent)continue;
//             mxHt = max(mxHt,getMaxht(adj,neighbor,node)+1);
//         }
//         return mxHt;
//     }
// public:
//     int assignEdgeWeights(vector<vector<int>>& edges) {
//         unordered_map<int,vector<int>>adj;

//     //as its a undirected tree , so a node can have multiple neighbors, so we store them efficiently as a adjancency list
//     //O(n)
//         for(auto& edge : edges){
//             int u = edge[0];
//             int v = edge[1];

//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         //d = maxht
//     //why 2^d-1  is the answer because , for every value of d there are total 2^d possibilities.
//     //like for d = 2 , total possibilities are 2^2 = 4 , and among these the possibility of  sum being odd or even is same
//     //so mathematically , poss(even sum) = poss(odd sum)
//     //poss(even sum) + poss(odd sum) = total possibility
//     //2*poss(odd sum) = 2^d
//     //poss(odd sum) = 2^(d-1)

//     //parent node is used to prevent infinite recursion , so that neighbors dont go back to their origin during depth finding
//     int maxht = getMaxht(adj,1,-1);

//     return BinaryExpo(2,maxht-1);

//     }
// };