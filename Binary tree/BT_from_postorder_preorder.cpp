// Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
// If there exist multiple answers, you can return any of them

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
// TreeNode* helper(vector<int>&preorder , vector<int>&  postorder , int lft , int rt , int& preIdx , int sz , unordered_map<int,int>&hash){

//     //empty subtree
//     if(lft > rt || preIdx >= sz)return nullptr;

//     //root node while traversing preorder array
//     TreeNode* root = new TreeNode(preorder[preIdx++]);

//     //no childrens means in case of leaf node
//     if(lft == rt)return root;

//     //find index of left node in postorder array in order to separate the array into regions for left and right subtree for given root node
//     int postIdx = hash[preorder[preIdx]];

//     if(postIdx <= rt){
//         root -> left = helper(preorder , postorder , lft , postIdx , preIdx , sz , hash);//left subtree = 0 - postIdx
//         root -> right = helper(preorder , postorder , postIdx+1 , rt-1 , preIdx , sz , hash);//right = postIdx + 1 to last node
//     }
//     return root;
// }
// public:
//     TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
//         unordered_map<int,int>hash;
//         int sz = preorder.size();

//         //a hashmap to store values and their indices using postorder array
//         for(int i = 0 ; i < sz ; i++)hash[postorder[i]] = i;

//         int preIdx = 0;

//         return helper(preorder,postorder,0,sz-1,preIdx,sz,hash);    
//     }
// };