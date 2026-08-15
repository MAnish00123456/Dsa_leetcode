// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.

// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]
// Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer 
// to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// class Solution {
// public:
//     Node* connect(Node* root) {
//         if(!root || !root->left)return root;
//         // queue<pair<Node*,int>>q;
//         // q.push({root,0});

//         // while(!q.empty()){
//         //     int sz = q.size();
//         //     while(sz--){
//         //         auto [n,l] = q.front();
//         //         q.pop();
//         //         if(!q.empty() && q.front().second == l){
//         //             n->next = q.front().first;
//         //         }else{
//         //             n->next = nullptr;
//         //         }
//         //         if(n->left)q.push({n->left,l+1});
//         //         if(n->right)q.push({n->right,l+1});
//         //     }
//         // }
//         // return root;

//     //left node points to right node if childs of same parent
//         root->left->next = root->right;
//         //for cousins , check if root->next exists
//         if(root->next){
//             root->right->next = root->next->left;
//         }
//         connect(root->left);
//         connect(root->right);
//         return root;
//     }
// };