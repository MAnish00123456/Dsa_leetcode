/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 //as lca is the first node closest to both given nodes and have both nodes in its subtrees
 //so using this thing , we can predict the pos of lca , as its a bst
 //if root val is smaller than both node values , we know that we need a bigger value that is closest to them , and root left subtree will have only smaller values , so instead we only search in right subtree
 //similarly if bogger value , we go in left subtree
 //case where both condition fails , will be our lca
 
// class Solution {
//     TreeNode* ans = nullptr;
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
//         if(root->val > p->val && root->val > q->val){
//             lowestCommonAncestor(root->left,p,q);
//         }
//         else if(root->val < p->val && root->val < q->val){
//             lowestCommonAncestor(root->right,p,q);
//         }
//         else{
//             ans = root;
//             return root;
//         }
//         return ans;
//     }
// };