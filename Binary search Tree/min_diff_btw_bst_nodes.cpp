// Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.


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
//     TreeNode* prev = nullptr;
// public:
//     int minDiffInBST(TreeNode* root) {
//      if(!root)return INT_MAX;
//      int ans = INT_MAX;
//      if(root->left){
//         int lftmin = minDiffInBST(root->left);
//         ans = min(ans,lftmin);
//      }   
//      if(prev != nullptr){
//         ans = min(ans,root->val-prev->val);
//      }
//      prev = root;
//      if(root->right){
//         int rtmin = minDiffInBST(root->right);
//         ans = min(ans,rtmin);
//      }
//      return ans;
//     }
// };