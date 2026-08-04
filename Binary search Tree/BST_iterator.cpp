// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

// BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
// boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
// int next() Moves the pointer to the right, then returns the number at the pointer.
// Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

// You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

// Input
// ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
// [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
// Output
// [null, 3, 7, true, 9, true, 15, true, 20, false]

// Explanation
// BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
// bSTIterator.next();    // return 3
// bSTIterator.next();    // return 7
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 9
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 15
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 20
// bSTIterator.hasNext(); // return False

//use an explicit stack to store nodes
//as its a bst so we can store nodes in inorder form , 
//when constructor is called we will store all left nodes starting with root

//and when next() is called we will return stack top node as it will store the first node in inorder traversal. but after we pop this node , we will check if it doesnt have any right child becausee of how inorder works
// (left root right) . so if its right child exist , we will store left nodes starting with this right node.

//hasnext() will always return true as long as stack is not empty

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
// class BSTIterator {
//     stack<TreeNode*>st;
//     void storeLeftNodes(TreeNode* root){
//         while(root != nullptr){
//             st.push(root);
//             root = root->left;
//         }
//     }
// public:
//     BSTIterator(TreeNode* root) {
//         storeLeftNodes(root);
//     }
    
//     int next() {
//         TreeNode* ans = st.top();
//         st.pop();
//         if(ans->right){
//             storeLeftNodes(ans->right);
//         }
//         return ans->val;
//     }
    
//     bool hasNext() {
//         return st.size()!=0;
//     }
// };

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */