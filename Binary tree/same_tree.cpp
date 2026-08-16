// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

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
//     bool isSameTree(TreeNode* p, TreeNode* q) {
       
//         bool isSame = true;
//         auto Preorder_travesal = [&](auto&& self , TreeNode* r1 , TreeNode* r2)->void{
//             if(!isSame)return;
//             if((r1 == nullptr && r2 != nullptr) || (r1 != nullptr && r2 == nullptr)){
//                 isSame = false;
//                 return;
//             }

//             if((r1!=nullptr && r2!=nullptr) &&  r1 -> val != r2 -> val){
//                 isSame = false;
//                 return;
//             }
//             if(r1 !=  nullptr && r2 !=nullptr)self(self,r1->left,r2->left);
//             if(r1 != nullptr && r2 != nullptr)self(self,r1->right,r2->right);
//         };
//         Preorder_travesal(Preorder_travesal,p,q);
//         return isSame;
//     }
// };
