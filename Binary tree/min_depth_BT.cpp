// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
// Note: A leaf is a node with no children.

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
//     int minDepth(TreeNode* root) {
//         if(root == nullptr)return 0;
//         queue<pair<TreeNode*,int>>Q;
//         Q.push({root,1});//Q stores current root and its depth from top of BT
//         while(!Q.empty()){
//             auto [root,depth] = Q.front();
//             Q.pop();
//             if(root -> left == nullptr && root -> right == nullptr)return depth;//its a leaf node , so we are at the lowest end we can reach from root node and we return the depth we acquired

//             //if root childs are present push them in queue with depth + 1 , as we are going one level up in depth
//             if(root->left != nullptr)Q.push({root->left,depth+1});
//             if(root->right != nullptr)Q.push({root->right,depth+1});
//         }
//         return Q.front().second;
//     }
// };