// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
// A leaf is a node with no children.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)  {}
 * };
 */
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int targetSum) {
//      bool hasPath = false;

//      auto dfs = [&](auto&&self,TreeNode*root,int targetSum)->void{
//         if(root == nullptr)return;
//         if(hasPath)return;
//         if( targetSum == root->val && root->left == nullptr && root->right == nullptr ){
//             hasPath = true;
//             return;
//         }
//         self(self,root->left,targetSum-root->val);
//         self(self,root->right,targetSum-root->val);
//      }; 
//      dfs(dfs,root,targetSum);
//      return hasPath;
//     }
// };