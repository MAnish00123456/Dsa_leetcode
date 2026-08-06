//GFG
// Given the root of a binary tree, convert it to a Doubly Linked List (DLL) in place, using the same node structure.

// The left and right pointers in the binary tree nodes should be used as prev and next pointers respectively in the resulting DLL.
// The DLL should be formed by performing an inorder traversal of the binary tree (i.e., Left -> Root -> Right).
// The first node in the inorder traversal (i.e., the leftmost node) should become the head of the DLL.
// Return the head of the resulting DLL

// Input: root = [1, 2, 3]
// Output: 
// 2 1 3
// 3 1 2
// Explanation: Inorder traversal visits 2, 1, 3. Node 2 becomes the head of the DLL, giving the list 2 <=> 1 <=> 3.

//apply similar concept as flatten Binary tree
//we will perform reverse inorder traversal
//start flattening from rightmost node then root then left and each time maintain a nextRight pointer which will point to the right node in tree for connection of previous nodes
//after making right connections , make left connections

/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/
// class Solution {
//     Node* nextRight = nullptr;
//     //instead of left root right we gonna do right root left
//     void flattenLL(Node* root){
//         if(!root)return;
//         flattenLL(root->right);
//         // root->left = nullptr;
//         root->right = nextRight;
//         nextRight = root;
//         flattenLL(root->left);
//     }
//   public:
//     Node* treeToDLL(Node* root) {
//         // code here
//         flattenLL(root);
//         Node* prev = nullptr;
//         Node* tmp = nextRight;
//         while(tmp != nullptr){
//             tmp->left = prev;
//             prev = tmp;
//             tmp = tmp->right;
//         }
//         return nextRight;
//     }
// };