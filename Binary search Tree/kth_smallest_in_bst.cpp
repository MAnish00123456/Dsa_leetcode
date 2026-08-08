// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

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
//     int kthSmallest(TreeNode* root, int k) {
//         int kthValue = INT_MAX;

//         auto dfs = [&](auto&& self , TreeNode* root)->void{
//             if(!root)return;
//             if(k == 0)return;

//             self(self,root->left);
//             if(k > 0){
//                 kthValue = root->val;
//                 k--;
//             }
//             self(self,root->right);
//         };

//         dfs(dfs,root);
//         return kthValue;
//     }
// };


//follow up ans
// An inorder traversal would become too expensive because each query is O(n). Instead, I'd augment each node with the size of its subtree and maintain those sizes during insertions and deletions. Then I can determine whether the kth element lies in the left subtree, is the current node, or lies in the right subtree by comparing k with the left subtree size. If the BST is balanced (such as an AVL or Red-Black Tree), insertion, deletion, and kth-smallest queries all take O(log n).

// Node* kth(Node* root,int k){

//     int left = size(root->left);

//     if(k == left+1)
//         return root;

//     if(k <= left)
//         return kth(root->left,k);

//     return kth(root->right,k-left-1);
// }