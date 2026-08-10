// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

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
//     void recoverTree(TreeNode* root) {
//     TreeNode* prev = nullptr , *first = nullptr , *second = nullptr;

//      auto dfs = [&](auto&& self , TreeNode* root)->void{
//         if(!root)return;
//         self(self,root->left);
//         if(prev != nullptr && prev->val > root->val){
//             //handle both cases at once
//             //first is only updated once ,  i.e , first node of problematic pair
//             if(!first){
//                 first = prev;
//             }
//             //second always stores last node of problematic pair
//             second = root;
//         }
//         prev = root;
//         self(self,root->right);
//      };
//      dfs(dfs,root);
//      swap(first->val,second->val); 
//     }
// };

//so we got in total of 2 cases for probelmatic pairs
//pairs are in form of {prev node , current node}
//in case 1 -> we got 2 problematic pairs , so we will stor our first pointer to first node of 1st pair and second pointer to second node of 2nd pair , atlast we will switch them
//in case 2 -> we got only 1 problematic pair , so we will swap values of first and second node
// case - i = inorder - [1,3,8,6,4,9]
// pairs -> {8,6}  ; {6,4} . so swap 8,6
// case - ii = inorder - [1,3,2,4]
// pair -> {2,4} , so swap 4 with 2