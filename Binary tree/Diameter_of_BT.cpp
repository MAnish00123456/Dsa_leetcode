// Given the root of a binary tree, return the length of the diameter of the tree.The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

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
//     int diameterOfBinaryTree(TreeNode* root) {
        
//         int ans = 0; 
//         auto height = [&](auto&&self , TreeNode*root)->int{
//             if(root == nullptr)return 0;
//             int lftheight = self(self,root->left);
//             int rtheight = self(self,root->right);
//             ans = max(ans,lftheight+rtheight);
//             return max(lftheight,rtheight)+1;
//         };

//         height(height,root);
//         return ans;

        // auto diameter = [&](auto&& self , TreeNode* root)->int{
        //     if(root == nullptr)return 0;
        //     int leftDiam = self(self,root->left);
        //     int rightDiam = self(self,root->right);
        //     int currDiam = height(height,root->left)+height(height,root->right);
        //     return max(max(leftDiam,rightDiam),currDiam);
        // };

        // return diameter(diameter,root);
//     }
// };