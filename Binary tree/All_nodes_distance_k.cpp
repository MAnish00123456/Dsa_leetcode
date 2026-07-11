// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
//      void inorder_trav(TreeNode* root ,  unordered_map<TreeNode*,TreeNode*>&parent){
//         if(root == nullptr)return;
//         if(root -> left != nullptr){
//             parent[root->left]=root;
//         }
//         inorder_trav(root->left,parent);
//         if(root -> right != nullptr){
//             parent[root->right]=root;
//         }
//         inorder_trav(root->right,parent);
//      }
// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

//         unordered_map<TreeNode*,TreeNode*>parent;
//         parent[root]=nullptr;
//         inorder_trav(root,parent);
        
//         queue<pair<TreeNode*,int>>q;
//         set<TreeNode*>s;
        
//         q.push({target,0});

//         while(!q.empty()){
//             auto[r,l] = q.front();
//             if(l == k)break;
//             s.insert(r);
//             q.pop();

//             if(r->left){
//                 if(s.find(r->left) == s.end()){
//                     q.push({r->left,l+1});
//                 }
//             }
//             if(r->right){
//                 if(s.find(r->right) == s.end()){
//                     q.push({r->right,l+1});
//                 }
//             }
//             if(parent[r]){
//                 if(s.find(parent[r]) == s.end()){
//                     q.push({parent[r],l+1});
//                 }
//             }
//         }

//         vector<int>Ans;
//         while(!q.empty()){
//             Ans.push_back(q.front().first->val);
//             q.pop();
//         }

//         return Ans;
//     }
// };