// // There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
// // Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
// // The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
// // You are given a 2D integer array queries. For each queries[i] = [ui, vi], determine the number of ways to assign weights to edges in the path such that the cost of the path between ui and vi is odd.
// // Return an array answer, where answer[i] is the number of valid assignments for queries[i].
// // Since the answer may be large, apply modulo 109 + 7 to each answer[i].
// // Note: For each query, disregard all edges not in the path between node ui and vi.

// // Input: edges = [[1,2],[1,3],[3,4],[3,5]], queries = [[1,4],[3,4],[2,5]]

// // Output: [2,1,4]

// // Explanation:

// // Query [1,4]: The path from Node 1 to Node 4 consists of two edges (1 → 3 and 3 → 4). Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.
// // Query [3,4]: The path from Node 3 to Node 4 consists of one edge (3 → 4). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
// // Query [2,5]: The path from Node 2 to Node 5 consists of three edges (2 → 1, 1 → 3, and 3 → 5). Assigning (1,2,2), (2,1,2), (2,2,1), or (1,1,1) makes the cost odd. Thus, the number of valid assignments is 4.

// class Solution {
//     #define ll long long

//     int mod = 1e9 + 7;

//     vector<int> Parent;                  // Stores immediate parent (2^0-th ancestor) of every node.
//     unordered_map<int,vector<int>> adj;  // Adjacency list of the tree.

//     vector<vector<int>> Ancestor;        // Binary Lifting Table.
//                                         // Ancestor[node][j] = 2^j-th ancestor of 'node'.

//     vector<int> depth;                   // Depth of every node from the root.

//     int rows;
//     int cols;

//     // ---------------------------------------------------------
//     // DFS to find immediate parent of every node.
//     // Parent[node] becomes the first column of Binary Lifting.
//     // ---------------------------------------------------------
//     void Findparent(int crntNode , int crntParent){

//         Parent[crntNode] = crntParent;

//         for(auto &neighbor : adj[crntNode]){

//             if(neighbor == crntParent)
//                 continue;

//             Findparent(neighbor,crntNode);
//         }
//     }

//     // ---------------------------------------------------------
//     // DFS to compute depth of every node.
//     //
//     // Required because:
//     // 1. LCA first brings both nodes to same depth.
//     // 2. Distance between nodes depends on depth.
//     // ---------------------------------------------------------
//     void dfs(int node , int parent , int crntdepth){

//         depth[node] = crntdepth;

//         for(auto ngbr : adj[node]){

//             if(ngbr == parent)
//                 continue;

//             dfs(ngbr,node,crntdepth+1);
//         }
//     }

//     // ---------------------------------------------------------
//     // Fill first column of Binary Lifting table.
//     //
//     // Ancestor[node][0]
//     // = immediate parent
//     // = 2^0-th ancestor.
//     // ---------------------------------------------------------
//     void fillup(int sz){

//         for(int i=0;i<=sz;i++){
//             Ancestor[i][0]=Parent[i];
//         }
//     }

//     // ---------------------------------------------------------
//     // Lowest Common Ancestor using Binary Lifting.
//     //
//     // Steps:
//     //
//     // 1. Lift deeper node until both nodes are at same depth.
//     // 2. Lift both nodes together from largest jump to smallest.
//     // 3. When they become children of LCA,
//     //    return their parent.
//     // ---------------------------------------------------------
//     int findLCA(int u , int v){

//         int orig=u;

//         // Ensure u is always the deeper node.
//         if(depth[u]<depth[v])
//             swap(u,v);

//         int diff=depth[u]-depth[v];

//         // Lift u upward according to set bits in 'diff'.
//         //
//         // Example:
//         // diff = 13 = 1101
//         // Jump:
//         // 2^0 + 2^2 + 2^3
//         for(int j=0;j<cols;j++){

//             if(diff&(1<<j)){
//                 u=Ancestor[u][j];
//             }
//         }

//         // If both meet after lifting,
//         // that node itself is the LCA.
//         if(u==v)
//             return depth[u]==depth[orig]?u:v;

//         // Lift both nodes together.
//         //
//         // Always try the largest jump first.
//         // Move only if their ancestors differ.
//         //
//         // After this loop,
//         // u and v become immediate children of LCA.
//         for(int j=cols-1;j>=0;j--){

//             if(Ancestor[u][j]!=-1 &&
//                Ancestor[u][j]!=Ancestor[v][j]){

//                 u=Ancestor[u][j];
//                 v=Ancestor[v][j];
//             }
//         }

//         // Parent of either node is now the LCA.
//         return Ancestor[u][0];
//     }

//     // ---------------------------------------------------------
//     // Binary Exponentiation
//     //
//     // Computes:
//     //
//     // base^expo % mod
//     //
//     // Time : O(log expo)
//     //
//     // Idea:
//     //
//     // expo = 13
//     // binary = 1101
//     //
//     // Process one bit at a time.
//     // Square the base every step.
//     // Multiply answer only when current bit is 1.
//     // ---------------------------------------------------------
//     ll binaryExpo(ll base , ll expo){

//         if(expo<0)
//             return 0;

//         if(expo==0)
//             return 1;

//         ll half=binaryExpo(base,expo/2);

//         ll res=(half*half)%mod;

//         if(expo%2==1){
//             res=(res*base)%mod;
//         }

//         return res;
//     }

// public:

//     vector<int> assignEdgeWeights(vector<vector<int>>& edges,
//                                   vector<vector<int>>& queries) {

//         // Convert edge list into adjacency list.
//         for(auto &edge:edges){

//             int u=edge[0];
//             int v=edge[1];

//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         int sz=edges.size()+1;

//         depth.resize(sz+1,0);
//         Parent.resize(sz+1,-1);

//         // -----------------------------
//         // Preprocessing
//         //
//         // Parent[]
//         // Depth[]
//         // -----------------------------
//         Findparent(1,-1);
//         dfs(1,-1,0);

//         rows=sz+1;
//         cols=log2(sz)+1;

//         Ancestor.resize(rows,vector<int>(cols,-1));

//         // Fill first column.
//         fillup(sz);

//         // --------------------------------------------------
//         // Build Binary Lifting Table.
//         //
//         // DP Relation:
//         //
//         // Ancestor[node][j]
//         //
//         // = 2^(j-1)-th ancestor
//         //   of node's 2^(j-1)-th ancestor.
//         //
//         // Ancestor[node][j]
//         // =
//         // Ancestor[
//         //      Ancestor[node][j-1]
//         // ][j-1]
//         //
//         // TC : O(N log N)
//         // --------------------------------------------------
//         for(int j=1;j<cols;j++){

//             for(int i=0;i<rows;i++){

//                 if(Ancestor[i][j-1]!=-1){

//                     Ancestor[i][j]=
//                     Ancestor[
//                         Ancestor[i][j-1]
//                     ][j-1];
//                 }
//             }
//         }

//         vector<int> Ans;

//         // --------------------------------------------------
//         // For every query:
//         //
//         // 1. Find LCA.
//         // 2. Compute distance.
//         // 3. Apply formula from Part 1:
//         //
//         // Answer = 2^(distance-1)
//         //
//         // Query TC : O(log N)
//         // --------------------------------------------------
//         for(auto &query:queries){

//             int u=query[0];
//             int v=query[1];

//             int LCA=findLCA(u,v);

//             int dist_u=depth[u]-depth[LCA];
//             int dist_v=depth[v]-depth[LCA];

//             int total_dist=dist_u+dist_v;

//             Ans.push_back(binaryExpo(2,total_dist-1));
//         }

//         return Ans;
//     }
// };

// /*
// ============================================================

// Algorithms Used

// ✓ DFS
// ✓ Parent Array
// ✓ Depth Array
// ✓ Binary Lifting
// ✓ Lowest Common Ancestor (LCA)
// ✓ Distance Between Two Nodes
// ✓ Binary Exponentiation

// ------------------------------------------------------------

// Distance Formula

// distance(u,v)
// =
// depth[u]
// +
// depth[v]
// -
// 2 * depth[LCA]

// ------------------------------------------------------------

// DP Relation

// Ancestor[node][j]

// =

// Ancestor[
//         Ancestor[node][j-1]
// ][j-1]

// ------------------------------------------------------------

// Complexities

// Preprocessing:
// DFS                -> O(N)
// Depth DFS          -> O(N)
// Binary Lifting     -> O(N log N)

// Overall:
// Time = O(N log N)

// Each Query:
// LCA + Binary Expo
// = O(log N)

// Space:
// Ancestor Table
// = O(N log N)

// ============================================================
// */