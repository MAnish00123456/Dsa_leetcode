// Given a binary tree, determine if it is height-balanced.
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {

//         bool isbalance = true;
//         auto dfs = [&](auto&& self, TreeNode* root) -> int {
//             if (root == nullptr)
//                 return 0;
//             if (!isbalance)
//                 return 0;
//             int lftheight = self(self, root->left);
//             int rtheight = self(self, root->right);
//             if (abs(lftheight - rtheight) > 1) {
//                 isbalance = false;
//                 return 0;
//             }

//             return max(lftheight, rtheight) + 1;
//         };
//         dfs(dfs, root);
//         return isbalance;
//     }
// };