// You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
// Return the minimum number of cameras needed to monitor all nodes of the tree.

// Input: root = [0,0,null,0,null,0,null,null,0]
// Output: 2
// Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement

/*
------------------------------------------------------------
Greedy + Postorder DFS

Idea:

A camera covers:
- Parent
- Current Node
- Left Child
- Right Child

Instead of asking:
"Where should I place cameras?"

Think:
"Which nodes are already covered?"

Process tree in postorder because a parent should decide
whether a camera is needed after both children are processed.

Greedy Rule:

If any child remains uncovered,
place a camera at the current node.

Reason:
A camera at the parent covers
- uncovered child
- current node
- parent

which is always better than placing it on the child.

Special Trick:

covered.insert(nullptr)

Treat nullptr as already covered so that
leaf nodes don't place cameras on themselves.
Their parent will handle them instead.

TC : O(N)
SC : O(N)
------------------------------------------------------------
*/

// class Solution {
//     public:
//         int minCameraCover(TreeNode* root) {
    
//             int cm = 0;
    
//             // Stores all nodes that are already covered by some camera.
//             // NOTE:
//             // This set does NOT store camera locations.
//             unordered_set<TreeNode*> covered;
    
//             // Treat nullptr as already covered.
//             //
//             // This prevents placing cameras on leaf nodes.
//             // Leaves should stay uncovered so that their parent
//             // is forced to place the camera instead.
//             covered.insert(nullptr);
    
//             auto dfs = [&](auto&& self, TreeNode* root, TreeNode* parent)->void{
    
//                 if(!root)
//                     return;
    
//                 // Process children first.
//                 // Camera placement decisions are made bottom-up.
//                 self(self, root->left, root);
//                 self(self, root->right, root);
    
//                 // Place camera if:
//                 //
//                 // 1. Root is still uncovered (special case).
//                 // 2. Any child is uncovered.
//                 //
//                 // Greedy Idea:
//                 // If a child is uncovered, placing camera at current node
//                 // is always better than placing it on the child because
//                 // it also covers the parent.
//                 if( (parent == nullptr && !covered.count(root)) ||
//                     (!covered.count(root->left) ||
//                      !covered.count(root->right)) ){
    
//                     cm++;
    
//                     // Camera covers:
//                     // parent
//                     // current node
//                     // left child
//                     // right child
//                     covered.insert(parent);
//                     covered.insert(root);
//                     covered.insert(root->left);
//                     covered.insert(root->right);
//                 }
//             };
    
//             dfs(dfs, root, nullptr);
    
//             return cm;
//         }
//     };