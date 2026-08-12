// Given the root of a binary tree, return the maximum width of the given tree.
// The maximum width of a tree is the maximum width among all levels.
// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes 
// that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
// It is guaranteed that the answer will in the range of a 32-bit signed integer.

// Input: root = [1,3,2,5,null,null,9,6,null,7]
// Output: 7
// Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

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
//     int widthOfBinaryTree(TreeNode* root) {

//      queue<pair<TreeNode*,uint64_t>>q;
//      q.push({root,0});
//      int maxWidth = 0;

//      while(!q.empty()){
//         int sz = q.size();
//         uint64_t endIdx = q.back().second;
//         uint64_t stIdx = q.front().second;
//         maxWidth = max(maxWidth,(int)(endIdx-stIdx+1));
//         while(sz--){
//             auto [n,idx] = q.front();
//             q.pop();
//             if(n->left)q.push({n->left,2*idx+1});
//             if(n->right)q.push({n->right,2*idx+2});
//         }
//      }
//      return maxWidth;
//     }
// };