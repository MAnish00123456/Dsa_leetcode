// You are given n BST (binary search tree) root nodes for n separate BSTs stored in an array trees (0-indexed). Each BST in trees has at most 3 nodes, and no two roots have the same value. In one operation, you can:

// Select two distinct indices i and j such that the value stored at one of the leaves of trees[i] is equal to the root value of trees[j].
// Replace the leaf node in trees[i] with trees[j].
// Remove trees[j] from trees.
// Return the root of the resulting BST if it is possible to form a valid BST after performing n - 1 operations, or null if it is impossible to create a valid BST.

// A BST (binary search tree) is a binary tree where each node satisfies the following property:

// Every node in the node's left subtree has a value strictly less than the node's value.
// Every node in the node's right subtree has a value strictly greater than the node's value.
// A leaf is a node that has no children.

// Input: trees = [[2,1],[3,2,5],[5,4]]
// Output: [3,2,5,1,null,4]
// Explanation:
// In the first operation, pick i=1 and j=0, and merge trees[0] into trees[1].
// Delete trees[0], so trees = [[3,2,5,1],[5,4]].

// In the second operation, pick i=0 and j=1, and merge trees[1] into trees[0].
// Delete trees[1], so trees = [[3,2,5,1,null,4]].


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

 /** 
 as we are given root of bst , we need to determine which root will become our final bst root node
 the property of this root node would be that it would not be leaf node of any bst , 
 2 failed case -> if we dont find any root or if we have root more than 1 , in these cases it is impossible to merge bst

 we will make hash map count  which will store count of all nodes across all trees , and then we will check which given root node count is 1 out of all given root nodes and try making a final bst using this root 

we will make another hash map valTonode which will store all root node values as keys mapped to root node address , this wil help in merging

now to merge , we will traverse both children of our final root node and for each leaf node we will try to see if we have any bst present with this root value , if yes , we will assign this final tree node childrens to given root node childrens
Do this for each leaf node for which we can find a root node of a bst

before merging nodes , we will also validate the nodes using min-max trick , which will help us to check if whether given node value is within the assigned range or not

atlast if we are able to make a bst and have only 1 root node , we will return this root else we return nullptr
 **/

// class Solution {
//     bool isValid(TreeNode* root,TreeNode* min , TreeNode* max , unordered_map<int,TreeNode*>& valToNode){
//         if(!root)return true;
//         if(min != nullptr && root->val <= min->val)return false;
//         if(max != nullptr && root->val >= max->val)return false;

//         if(!root->left && !root->right  && valToNode.contains(root->val)){
//             int val = root->val;
//             root->left = valToNode[val]->left;
//             root->right = valToNode[val]->right;
//             valToNode.erase(val);
//         }

//         return isValid(root->left,min,root,valToNode)&&isValid(root->right,root,max,valToNode);
//     }
// public:
//     TreeNode* canMerge(vector<TreeNode*>& trees) {
//         unordered_map<int,TreeNode*>valToNode;
//         unordered_map<int,int>CountNodes;

//         for(auto& tree : trees){
//             valToNode[tree->val] = tree;
//             CountNodes[tree->val]++;
//             if(tree->left)CountNodes[tree->left->val]++;
//             if(tree->right)CountNodes[tree->right->val]++;
//         }
//         for(auto [k,v] : valToNode){
//             cout<<k<<" "<<v<<endl;
//         }
//         for(auto& tree : trees){
//             if(CountNodes[tree->val] == 1){
//                 if(isValid(tree,nullptr,nullptr,valToNode) && valToNode.size() <= 1){
//                     return tree;
//                 }
//                 return nullptr;
//             }
//         }
//         return nullptr;
//     }
// };