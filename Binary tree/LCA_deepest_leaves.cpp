// Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

// Recall that:

// The node of a binary tree is a leaf if and only if it has no children
// The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
// The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.
 

// Input: root = [3,5,1,6,2,0,8,null,null,7,4]
// Output: [2,7,4]
// Explanation: We return the node with value 2, colored in yellow in the diagram.
// The nodes coloured in blue are the deepest leaf-nodes of the tree.
// Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
//     private:
//     //stores depth and LCA
//     //bottom up solution
//     pair<int,TreeNode*>solve(TreeNode* root){
//         if(root == nullptr){
//             return {0,nullptr};
//         }

//         auto l = solve(root->left);
//         auto r = solve(root->right);

//         if(l.first == r.first){
//             return {l.first+1,root};
//         }else if(l.first > r.first){
//             return {l.first+1,l.second};
//         }else{
//             return {r.first+1,r.second};
//         }

//     }
// public:
//     TreeNode* lcaDeepestLeaves(TreeNode* root) {
//         return solve(root).second;
//     }
// };