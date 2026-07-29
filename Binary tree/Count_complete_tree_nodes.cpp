// Given the root of a complete binary tree, return the number of the nodes in the tree.
// According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. 
// It can have between 1 and 2h nodes inclusive at the last level h.
// Design an algorithm that runs in less than O(n) time complexity.

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

 //as its a complete Binary tree , we can use math formula to find number of nodes.
 //we will find left and right of tree , if both are equal we have (2^lh+1)-1 nodes else we have 1 + count of nodes in left and count of nodes in right
 //this takes O((logn)^2) TC
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if(!root)return 0;

//         int lftHeight = 0;
//         TreeNode* lft = root;
//         while(lft->left){
//             lftHeight++;
//             lft = lft->left;
//         }

//         int rtHeight = 0;
//         TreeNode* rt = root;
//         while(rt->right){
//             rtHeight++;
//             rt = rt->right;
//         }
// //height match -> perfect binary tree. formula 2^(height + 1) - 1
//         if(lftHeight == rtHeight){
//             return (1 << (lftHeight+1))-1;
//         }
//         //height doesnt match , recurse for left and right subtrees
//         return 1 +  countNodes(root->left) + countNodes(root->right);
//     }
// };