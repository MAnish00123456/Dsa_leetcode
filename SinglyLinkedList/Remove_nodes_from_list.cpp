// You are given the head of a linked list.
// Remove every node which has a node with a greater value anywhere to the right side of it.
// Return the head of the modified linked list.

// Helper function to reverse a linked list in-place
// This is used twice:
// 1. To process nodes from right → left
// 2. To restore original order at the end
// ListNode* reverseList(ListNode* head){
//     ListNode* prev = nullptr;   // Will become new head
//     ListNode* curr = head;      // Start from current head

//     while(curr){
//         // Store next node before breaking link
//         ListNode* forward = curr->next;

//         // Reverse current node's pointer
//         curr->next = prev;

//         // Move pointers forward
//         prev = curr;
//         curr = forward;
//     }

//     // 'prev' is the new head after reversal
//     return prev;
// }

// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {

//         // Edge case: empty list
//         if(!head) return head;

//         // Step 1: Reverse the list
//         // This allows us to process from right to left
//         // (since original problem depends on "future" nodes)
//         head = reverseList(head);

//         // Step 2: Traverse and remove smaller nodes
//         // Maintain the maximum value seen so far
//         ListNode* curr = head;
//         ListNode* next = curr->next;

//         while(next){

//             // If next node is smaller, remove it
//             if(next->val < curr->val){
//                 ListNode* temp = next;

//                 // Skip the node
//                 curr->next = next->next;

//                 // Move forward
//                 next = next->next;

//                 // Free memory (important in C++)
//                 delete temp;
//             }
//             else{
//                 // Update max (move curr forward)
//                 curr = next;
//                 next = next->next;
//             }
//         }

//         // Step 3: Reverse again to restore original order
//         return reverseList(head);
//     }
// };

