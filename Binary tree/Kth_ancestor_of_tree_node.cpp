// You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.
// The kth ancestor of a tree node is the kth node in the path from that node to the root node.
// Implement the TreeAncestor class:
// TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.
// int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there is no such ancestor, return -1.

// Input
// ["TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"]
// [[7, [-1, 0, 0, 1, 1, 2, 2]], [3, 1], [5, 2], [6, 3]]
// Output
// [null, 1, 0, -1]

// Explanation
// TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
// treeAncestor.getKthAncestor(3, 1); // returns 1 which is the parent of 3
// treeAncestor.getKthAncestor(5, 2); // returns 0 which is the grandparent of 5
// treeAncestor.getKthAncestor(6, 3); // returns -1 because there is no such ancestor
 
// Binary Lifting
// Instead of moving to the parent one step at a time,
// precompute ancestors at distances 2^0, 2^1, 2^2, ...
// This allows each query to jump upward in O(log N).

// Ancestor[i][j] = Ancestor[ Ancestor[i][j-1] ][j-1]
//answer queries in O(nlogn)
// class TreeAncestor {

//     // Build the binary lifting table.
//     // Ancestor[i][j] = 2^j-th ancestor of node i.
//     void fillup(vector<int>& parent, vector<vector<int>>& Ancestor,
//                 int rows, int cols) {

//         // Base case:
//         // 2^0-th ancestor is the immediate parent.
//         //o(n)
//         for (int i = 0; i < rows; i++) {
//             Ancestor[i][0] = parent[i];
//         }

//         // DP relation:
//         // 2^j-th ancestor =
//         // 2^(j-1)-th ancestor of the 2^(j-1)-th ancestor.
//         //O(nlogn)
//         for (int j = 1; j < cols; j++) {//O(logn)
//             for (int i = 0; i < rows; i++) {//O(n)

//                 // Only compute if the previous ancestor exists.
//                 if (Ancestor[i][j - 1] != -1) {
//                     Ancestor[i][j] =
//                         Ancestor[Ancestor[i][j - 1]][j - 1];
//                 }
//             }
//         }
//     }

//     int rows = 0, cols = 0;
//     vector<vector<int>> Ancestor;

// public:
//     TreeAncestor(int n, vector<int>& parent) {

//         rows = parent.size();

//         // Maximum power of two needed.
//         cols = log2(n) + 1;

//         Ancestor.assign(rows, vector<int>(cols, -1));

//         fillup(parent, Ancestor, rows, cols);
//     }

//     int getKthAncestor(int node, int k) {

//         // Check every set bit in k.
//         // If bit j is set, jump upward by 2^j.
//         //O(logn)
//         for (int j = 0; j < cols; j++) {

//             if (k & (1 << j)) {

//                 node = Ancestor[node][j];

//                 // No ancestor exists beyond this point.
//                 if (node == -1)
//                     return -1;
//             }
//         }

//         return node;
//     }
// };