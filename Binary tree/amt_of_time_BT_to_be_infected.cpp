// You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.
// Each minute, a node becomes infected if:
// The node is currently uninfected.
// The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.

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
//     void buildParent(TreeNode* root,
//                      unordered_map<TreeNode*, TreeNode*>& parent,
//                      TreeNode*& target, int start) {
//         if (root == nullptr)
//             return;
//         if (root->val == start) {
//             target = root;
//         }
//         if (root->left) {
//             parent[root->left] = root;
//         }
//         buildParent(root->left, parent, target, start);
//         if (root->right) {
//             parent[root->right] = root;
//         }
//         buildParent(root->right, parent, target, start);
//     }

// public:
//     int amountOfTime(TreeNode* root, int start) {
//         unordered_map<TreeNode*, TreeNode*> parent;
//         parent[root] = nullptr;
//         TreeNode* target = nullptr;
//         buildParent(root, parent, target, start);

//         int min = -1;
//         queue<TreeNode*> q;
//         unordered_set<TreeNode*> s;
//         s.insert(target);
//         q.push(target);

//         while (!q.empty()) {
//             int sz = q.size();
//             min++;
//             while (sz--) {
//                 TreeNode* r = q.front();
//                 q.pop();

//                 if (r->left != nullptr) {
//                     if (!s.contains(r->left)) {
//                         s.insert(r->left);
//                         q.push(r->left);
//                     }
//                 }
//                 if (r->right != nullptr) {
//                     if (!s.contains(r->right)) {
//                         s.insert(r->right);
//                         q.push(r->right);
//                     }
//                 }
//                 if (parent[r]) {
//                     if (!s.contains(parent[r])) {
//                         s.insert(parent[r]);
//                         q.push(parent[r]);
//                     }
//                 }
//             }
//         }
//         return min;
//     }
// };
