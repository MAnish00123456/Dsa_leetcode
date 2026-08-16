// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

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
// public:
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         if(root == nullptr || subRoot == nullptr)return root ==  subRoot;
//         if(root -> val == subRoot->val && isSameTree(root,subRoot))return true;
//         return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);   
//     }
// };