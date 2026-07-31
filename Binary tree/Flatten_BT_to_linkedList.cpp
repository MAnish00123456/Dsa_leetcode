// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]

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
//     TreeNode* nextRight = nullptr;
// public:
//     void flatten(TreeNode* root) {
//         //use trick of reverse traversal
//         //means instead of going root left right , we will go backwards , right left root
//         //as it is easier to reconnect nodes in reversal traversal

//         //each time we go to new node , we will store a nextRight node which will be the node that will be connected to right side of current node during flattening
//         if(!root)return;
//         flatten(root->right);
//         flatten(root->left);
//         root->left = nullptr;
//         root->right = nextRight;
//         nextRight = root;//now root is the nextRight node which will be connected to our node right side
//     }
// };