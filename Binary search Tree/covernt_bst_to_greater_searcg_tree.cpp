// Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.
// As a reminder, a binary search tree is a tree that satisfies these constraints:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
// Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

//as we want each node val replaced with total sum of keys greater than it.
//its a bst so we know for each node , the larger values will always be in right subtree , thats why , we will use reverse inorder traversal , we start from right root left
//and each time we will update current root and a global sum

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
//     TreeNode* convertBST(TreeNode* root) {
//         int sum = 0;

//         auto dfs = [&](auto&& self , TreeNode* root)->void{
//             if(!root)return;
//             self(self,root->right);
//             int val = root->val;
//             root->val = root->val + sum;
//             sum += val;
//             self(self,root->left); 
//         };

//         dfs(dfs,root);
//         return root;
//     }
// };