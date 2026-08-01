// Given the root of a binary tree, invert the tree, and return its root.


//simply swap left and right child for each node

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
//     TreeNode* invertTree(TreeNode* root) {

//      auto dfs = [](auto&& self ,TreeNode* root)->void{
//         if(root == nullptr)return;

//         TreeNode* tmp = root->left;
//         root->left = root->right;
//         root->right = tmp;

//         self(self,root->left);
//         self(self,root->right);
//      };
     
//      dfs(dfs,root);
//      return root;
//     }
// };
