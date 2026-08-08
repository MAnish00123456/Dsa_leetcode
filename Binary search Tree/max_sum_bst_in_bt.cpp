// Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
// Output: 20
// Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.


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
//    struct Treeinfo{
//     bool isBst;
//     int sum;
//     int minVal;
//     int maxVal;
//    };
//     int maxSum = 0;
    //build solution bottom up.
    //if left and right subtree is a bst for any parent node, then we can check if combining parent node makes a bigger bst or not
    // and pass this information above
//    Treeinfo helper(TreeNode* root){
    //empty tree is a valid BST
    // if(!root)return {true,0,INT_MAX,INT_MIN};
    //collect data for child nodes and pass it up to parent node
    // Treeinfo left = helper(root->left);
    // Treeinfo right = helper(root->right);

    // Treeinfo current;
    //Current Node is bst if :
    //its left subtree is bst
    //its right subtree is bst
    //Current Node val is bigger than left subtree max val and is smaller than right subtree min val
    // if(left.isBst && right.isBst && root->val > left.maxVal && root->val < right.minVal){
    //     current.isBst = true;
    //     current.sum = left.sum + right.sum + root->val;
        //current node minVal can be node value itself(if its a leaf node) or leftsubtree min val
        //same goes for maxval
        // current.minVal = min(root->val,left.minVal);
        // current.maxVal = max(root->val,right.maxVal);
        // maxSum = max(maxSum,current.sum);
    // }else{
        //if adding current node doesnt create a bigger bst , we will mark it as not a bst with base values
//         current.isBst = false;
//         current.sum = 0;
//         current.minVal = INT_MIN;
//         current.maxVal = INT_MAX;
//     }
//     return current;
//    }
// public:
//     int maxSumBST(TreeNode* root) {
//              maxSum = 0;
//             helper(root);
//                 return  maxSum;
//     }
// };