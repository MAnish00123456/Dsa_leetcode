// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only
//  appear in the sequence at most once. Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.

// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

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

 //there are 3 cases to find path sum:-
    // i)when we include both our left subtree sum and right subtree sum with out root value(as this path sum converges downwards so we wont return this sum in recursion)
    // ii) when we include either our left subtree sum or right subtree sum (whichever have larger sum value) with our root value , as only 1 part of tree is in consideration , the path can extend upwards so we will return it
    // iii) last case is when both our left subtree sum and right subtree sum are not viable to choose so we only take root value in consideration

    //in recusion call , for each stack trace we will return max(case ii sum value , case iii sum value)
// class Solution {
// public:
//     int maxPathSum(TreeNode* root) {
//         int maxSum = INT_MIN;

//         auto dfs = [&](auto&& self,TreeNode* root)->int{
//             if(!root)return 0;

//             int lftSum = self(self,root->left);
//             int rtSum = self(self,root->right);

//             //3 cases
//             int case_i_sum = lftSum + rtSum + root->val;//considering path converging at root 
//             int case_ii_sum = max(lftSum,rtSum) + root->val;//straight path , can extend upwards
//             int case_iii_sum = root->val;//current node is best instead of its subtree

//             maxSum = max(maxSum,max(case_i_sum,max(case_ii_sum,case_iii_sum)));

//             return max(case_ii_sum,case_iii_sum);
//         };

//         dfs(dfs,root);
//         return maxSum;
//     }
// };