//given a binary tree level wise traversal values
//check whether its a valid bst or not
//its not sure than given order is for complete binary tree or not
//so we will instead of creating a bt , will directly check if its valid or not using min,max range

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <climits>

// // Structure to store a node's value and its valid range
// struct NodeDetails {
//     int val;
//     long long min_val;
//     long long max_val;
// };

// bool isValidBSTFromLevelOrder(const std::vector<int>& arr) {
//     if (arr.empty()) return true;

//     // Queue stores the node details (value, min allowed, max allowed)
//     std::queue<NodeDetails> q;
    
//     // Initialize root with absolute boundaries
//     int i = 0;
//     NodeDetails root = {arr[i++], LLONG_MIN, LLONG_MAX};
//     q.push(root);

//     // Process all elements in the level order array
//     while (i < arr.size() && !q.empty()) {
//         NodeDetails parent = q.front();
//         q.pop();

//         // Check if the next array element can be the LEFT child
//         if (i < arr.size() && arr[i] > parent.min_val && arr[i] < parent.val) {
//             NodeDetails left_child = {arr[i++], parent.min_val, parent.val};
//             q.push(left_child);
//         }

//         // Check if the next array element can be the RIGHT child
//         if (i < arr.size() && arr[i] > parent.val && arr[i] < parent.max_val) {
//             NodeDetails right_child = {arr[i++], parent.val, parent.max_val};
//             q.push(right_child);
//         }
//     }

//     // If we successfully placed all array elements, it is a valid BST
//     return i == arr.size();
// }

// int main() {
//     int n;
//     if (!(std::cin >> n)) return 0;

//     std::vector<int> arr(n);
//     for (int i = 0; i < n; ++i) {
//         std::cin >> arr[i];
//     }

//     if (isValidBSTFromLevelOrder(arr)) {
//         std::cout << "true" << std::endl;
//     } else {
//         std::cout << "false" << std::endl;
//     }

//     return 0;
// }


//if we are sure its a complete binary tree


// // Define the TreeNode structure
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// // Function to construct the tree from level-order vector
// TreeNode* constructTree(const std::vector<int>& arr) {
//     if (arr.empty()) return nullptr;

//     // Create root node
//     TreeNode* root = new TreeNode(arr[0]);
    
//     // Queue to keep track of parent nodes
//     std::queue<TreeNode*> q;
//     q.push(root);

//     size_t i = 1;
//     while (i < arr.size() && !q.empty()) {
//         TreeNode* current = q.front();
//         q.pop();

//         // Assign left child
//         if (i < arr.size()) {
//             current->left = new TreeNode(arr[i++]);
//             q.push(current->left);
//         }

//         // Assign right child
//         if (i < arr.size()) {
//             current->right = new TreeNode(arr[i++]);
//             q.push(current->right);
//         }
//     }
//     return root;
// }

// // Helper function to print tree level-by-level to verify
// void printLevelOrder(TreeNode* root) {
//     if (!root) return;
//     std::queue<TreeNode*> q;
//     q.push(root);
    
//     while (!q.empty()) {
//         TreeNode* curr = q.front();
//         q.pop();
//         std::cout << curr->val << " ";
//         if (curr->left) q.push(curr->left);
//         if (curr->right) q.push(curr->right);
//     }
//     std::cout << std::endl;
// }

// int main() {
//     std::vector<int> levelOrder = {20, 10, 30, 5, 15};
    
//     TreeNode* root = constructTree(levelOrder);
    
//     std::cout << "Constructed Tree (Level-order verification): ";
//     printLevelOrder(root); // Output: 20 10 30 5 15 

//     return 0;
// }
