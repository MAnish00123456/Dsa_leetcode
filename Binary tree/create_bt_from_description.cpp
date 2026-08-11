// You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

// If isLefti == 1, then childi is the left child of parenti.
// If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.

// The test cases will be generated such that the binary tree is valid.

// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
// Explanation: The root node is the node with value 50 since it has no parent.
// The resulting binary tree is shown in the diagram.

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
//      unordered_set<int>children;
//      unordered_map<int,vector<pair<int,int>>>Hash;

//     TreeNode* buildTree(int rVal){
//         TreeNode* root = new TreeNode(rVal);
//         for(auto child : Hash[rVal]){
//                 if(child.second == 1){
//                     root->left = buildTree(child.first);
//                 }else{
//                     root->right = buildTree(child.first);
//                 }
//         }
//         return root;        
//     }

// public:
//     TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
//      int rVal;
//      //to find root node :
//      for(auto& description : descriptions){
//         children.insert(description[1]);
//      }   
//         for(auto description : descriptions){
//             if(!children.contains(description[0])){
//                 rVal = description[0];
//                 break;
//             }
//         }
    
//     //store all parent node as keys and child and leftRight counter as vector<pairs> for efficient traversal
//     for(auto& description : descriptions){
//         Hash[description[0]].push_back({description[1],description[2]});
//     }

//       return  buildTree(rVal);

//     }
// };