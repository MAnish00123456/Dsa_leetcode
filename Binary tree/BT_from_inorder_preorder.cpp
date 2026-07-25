// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

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
//     TreeNode* helper(vector<int>& preorder , vector<int>& inorder , int st , int end , int& preIdx , int sz , unordered_map<int,int>&hash){
//         if(preIdx >= sz || st > end)return nullptr;

//         int curr = preorder[preIdx++];
//         TreeNode* root = new TreeNode(curr);
        
//         if(st == end)return root;

//         int iIdx = hash[curr];
//         root->left = helper(preorder,inorder,st,iIdx-1,preIdx,sz,hash);      
//         root->right  = helper(preorder,inorder,iIdx+1,end,preIdx,sz,hash);      
//         return root;    
//     }
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int len = preorder.size();
//         unordered_map<int,int>hash;
//         for(int i = 0 ; i < inorder.size() ; i++)hash[inorder[i]] = i;
//         int preIdx = 0;
//         return helper(preorder,inorder,0,len-1,preIdx,len,hash);      
//     }
// };
 