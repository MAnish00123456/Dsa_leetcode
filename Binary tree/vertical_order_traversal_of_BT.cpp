// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. 
// There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
// Return the vertical order traversal of the binary tree.

// Input: root = [1,2,3,4,5,6,7]
// Output: [[4],[2],[1,5,6],[3],[7]]
// Explanation:
// Column -2: Only node 4 is in this column.
// Column -1: Only node 2 is in this column.
// Column 0: Nodes 1, 5, and 6 are in this column.
//           1 is at the top, so it comes first.
//           5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
// Column 1: Only node 3 is in this column.
// Column 2: Only node 7 is in this column.

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
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         //a map of maps.
//         //each entry stores column value as key and a map as value
//         //the other map stores  all row indices present in that column value as key and vector of integers as values . this vector stores all node values that are present in that current row
//      map<int,map<int,vector<int>>>hash;
//      //queue stores node and its row and col
//      queue<pair<TreeNode*,pair<int,int>>>q;

//      q.push({root,{0,0}});

//      while(!q.empty()){
//         auto [n,idx] = q.front();
//         auto [rw,cl] = idx;
//         q.pop();
//         hash[cl][rw].push_back(n->val);
//         if(n->left)q.push({n->left,{rw+1,cl-1}});
//         if(n->right)q.push({n->right,{rw+1,cl+1}});
//      }  
//      vector<vector<int>>Ans;
//      for(auto& [cl,mp] : hash){
//     vector<int>tmp;
//         for(auto& [rw,vc] : mp){
//             sort(vc.begin(),vc.end());
//             tmp.insert(tmp.end(),vc.begin(),vc.end());
//         }
//     Ans.push_back(tmp);
//      } 
//      return Ans;
//     }
// };