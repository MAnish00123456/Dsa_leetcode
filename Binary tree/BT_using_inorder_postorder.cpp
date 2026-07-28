// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// class Solution {
//     // st and end index to traverse our inorder array
//     // pIdx is the last index of element in postorder array , as it is our root
//     TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int st,
//                      int end, int& pIdx, unordered_map<int, int>& hash) {

//         if (st > end)
//             return nullptr; // when st idx exceeds our inorder array size , empty subtree

//         int curr = postorder[pIdx];
//         TreeNode* node = new TreeNode(curr);
//         pIdx--;

//         // this node doesnt have any child nodes //leaf node
//         if (st == end)
//             return node;

//         int iIdx = hash[curr]; // for this last value in postorder array , we
//                                // will find its existing index in inorder array
//                                // to get its left and right subtrees

//         node->right = helper(inorder, postorder, iIdx + 1, end, pIdx, hash);
//         node->left = helper(inorder, postorder, st, iIdx - 1, pIdx, hash);

//         return node;
//     }

// public:
//     // inorder = left root right
//     // postorder = left right root
//     // using postorder we find last root index in inorder array and then we will
//     // get left and right children for this root node
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

//         // store values and their indices in map for O(1) access
//         unordered_map<int, int> hash;
//         for (int i = 0; i < inorder.size(); i++) {
//             hash[inorder[i]] = i;
//         }
//         int len = inorder.size();
//         int pIdx = len - 1;
//         // starting root node will be the last value in postorderarray
//         return helper(inorder, postorder, 0, len - 1, pIdx, hash);
//     }
// };