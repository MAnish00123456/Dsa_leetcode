// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Input: root = [1,2,3,4,null,null,null,5]
// Output: [1,3,4,5]

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
//     vector<int> rightSideView(TreeNode* root) {
//         if(!root)return {};
//         queue<pair<TreeNode*,int>>q;
//         map<int,TreeNode*>hash;
//         q.push({root,0});

//         while(!q.empty()){
//             auto [n,l] = q.front();
//             q.pop();
//             if(hash.find(l) == hash.end()){
//                 hash[l] = n;
//             }
//             if(n->right)q.push({n->right,l+1});
//             if(n->left)q.push({n->left,l+1});
//         }

//         vector<int>Ans;

//         for(const auto& [k,v] : hash){
//             Ans.push_back(v->val);
//         }
//         return Ans;
//     }
// };