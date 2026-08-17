// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

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
//     bool isSymmetric(TreeNode* root) {
//         auto dfs = [](auto&&self , TreeNode*left,TreeNode*right)->bool{
//             if(left == nullptr || right==nullptr){
//                 return left == right;
//             }
//             if(left->val != right->val){
//                 return false;
//             }

//             return self(self,left->left,right->right)&&self(self,left->right,right->left);            
//         };
//         return dfs(dfs,root->left,root->right);
//     }
// };