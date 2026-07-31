// A binary tree is named Even-Odd if it meets the following conditions:
// The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
// For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
// For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
// Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

// Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
// Output: true
// Explanation: The node values on each level are:
// Level 0: [1]
// Level 1: [10,4]
// Level 2: [3,7,9]
// Level 3: [12,8,6,2]
// Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.

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
//     bool isEvenOddTree(TreeNode* root) {

//      queue<pair<TreeNode*,int>>q;
//      q.push({root,0});

//      while(!q.empty()){
//      int Prev_vl_even = -1;
//      int Prev_vl_odd = INT_MAX;
//         int sz = q.size();
//         while(sz--){
//             auto [n,lvl] = q.front();
//             q.pop();
//             int currval = n->val;
//             if(lvl%2 == 0){
//                 if(currval%2 == 0 || currval <= Prev_vl_even){
//                     return false;
//                 }
//                 Prev_vl_even = currval;
//             }else{
//                 if(currval%2 != 0 || currval >= Prev_vl_odd){
//                     return false;
//                 }
//                 Prev_vl_odd =currval;
//             }
//             if(n->left)q.push({n->left,lvl+1});
//             if(n->right)q.push({n->right,lvl+1});
//         }
//      }   
//      return true;
//     }
// };