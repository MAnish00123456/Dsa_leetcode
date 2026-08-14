// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

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
// //code i wrote
//     int pathSum(TreeNode* root, int targetSum) {
//         if(!root)return 0;
//         int cnt = 0;
        
//         auto dfs = [&](auto&&self , TreeNode* root , long long targetSum)->void{
//             if(!root)return;

//             if(targetSum == root->val){
//                 cnt++;  
//             }

//             self(self,root->left,targetSum-root->val); 
//             self(self,root->right,targetSum-root->val); 

//         };
//         //dfs call to include current root and look for paths
//         dfs(dfs,root,targetSum);

//         //recursively call for every root left and right child to find independent paths that add upto targetSum and doesnt include root
//         cnt += pathSum(root->left,targetSum);
//         cnt += pathSum(root->right,targetSum);
//         return cnt;
//     }
// };

//approach i saw for optimization
//A more better approach is to use hashMap and running sum to find all pahts that add upto target
//its like a two sum or count subarray sum type problem

// class Solution {
// public:
//      int pathSum(TreeNode* root, int targetSum) {
//         unordered_map<long long,int>hash;//store running sum and count of occurences
//         int cnt = 0;
//         long long runSum = 0;
//         hash[0] = 1;
//         auto dfs = [&](auto&&self , TreeNode* root)->void{
//             if(!root)return;

//             runSum += root->val;
//             if(hash.count(runSum-targetSum)){
//                 cnt += hash[runSum-targetSum];
//             }

//             hash[runSum]++;
//             self(self,root->left);
//             self(self,root->right);
//             hash[runSum]--;
//             runSum -= root->val;
//         };
//         dfs(dfs,root);
//         return cnt;
//      }
// };