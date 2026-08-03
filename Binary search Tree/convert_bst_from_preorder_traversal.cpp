// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

// It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

// A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

// A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right

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
    // TreeNode* BuildTree(vector<int>&preorder,unordered_map<int,int>&hash,int st , int end , int sz , int& preIdx){
    //     if(preIdx >= sz || st > end)return nullptr;

    //     int curr = preorder[preIdx++];
    //     TreeNode* root = new TreeNode(curr);

    //     if(st == end)return root;

    //     int iIdx = hash[curr];
    //     root->left = BuildTree(preorder,hash,st,iIdx-1,sz,preIdx);
    //     root->right = BuildTree(preorder,hash,iIdx+1,end,sz,preIdx);

    //     return root;
    // }
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
        // vector<int>Inorder = preorder;
        // sort(Inorder.begin(),Inorder.end());
        // unordered_map<int,int>hash;
        // int len = preorder.size();
        // for(int i = 0 ; i < Inorder.size() ; i++)hash[Inorder[i]]=i;
        // int preIdx = 0;
        // return BuildTree(preorder,hash,0,len-1,len,preIdx);

        // 2nd approach -> use of min/max range for building of each node
        // as its BST , so each node have a fix range for values and this range depends on parent node
        // in this problem , we will use our upper bound for each node
        // left subtree , upper bound would be parent node value 
        // and for right subtree , upper bound would be same as parent node upper bound

//         int idx = 0;
//         auto dfs = [&](auto&& self , int Ubound)->TreeNode*{
//             if(idx >= preorder.size() || Ubound < preorder[idx])return nullptr;

//             TreeNode* root = new TreeNode(preorder[idx++]);
//             root->left = self(self,root->val);
//             root->right = self(self,Ubound);
//             return root;
//         };

//         return dfs(dfs,INT_MAX);
//     }
// };