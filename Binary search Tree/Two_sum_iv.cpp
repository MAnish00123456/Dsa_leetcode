// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

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
// public:
//     bool findTarget(TreeNode* root, int k) {
//         unordered_set<int>hashset;
//         bool ans = false;

//         auto dfs = [&](auto&& self , TreeNode*root)->void{
//             if(!root)return;
//             if(ans)return;
//             self(self,root->left);
//             if(hashset.find(k-root->val) != hashset.end()){
//                 ans = true;
//                 return;
//             }
//             hashset.insert(root->val);
//             self(self,root->right);
//         };
//         dfs(dfs,root);
//         return ans;
//     }
// };

