// // Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {

//         // Edge case: empty list → nothing to remove
//         if(!head) return head;

//         // 'curr' traverses the list
//         // 'prev' keeps track of the last valid (non-deleted) node
//         ListNode* curr = head;
//         ListNode* prev = nullptr;

//         // Traverse entire list
//         while(curr){

//             // Case 1: current node needs to be deleted
//             if(curr->val == val){

//                 // If 'prev' exists → bypass current node
//                 // i.e., remove current node by linking prev to next
//                 if(prev){
//                     prev->next = curr->next;
//                 }
//                 else{
//                     // If 'prev' is NULL → we are deleting the head
//                     // Move head forward
//                     head = curr->next;
//                 }

//                 // Note: we do NOT move 'prev' here,
//                 // because current node is removed and shouldn't be tracked
//             }
//             else{
//                 // Case 2: current node is valid → move 'prev' forward
//                 prev = curr;
//             }

//             // Always move 'curr' forward
//             curr = curr->next;
//         }
            // delete curr;
//         // Return updated head of the list
//         return head;
//     }
// };