// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
// for ex : list = 1 -> 2 -> 3 -> 4
//         updated list = 2 -> 1 -> 4 -> 3 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 * };
 */

// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {

//         // Edge case:
//         // If list is empty or contains only one node,
//         // no swapping is needed
//         if(!head || !head->next) return head;

//         /*
//          * Dummy node helps simplify pointer manipulation,
//          * especially when swapping starts from the head.
//          *
//          * Example:
//          * dummy -> 1 -> 2 -> 3 -> 4
//          */
//         ListNode* dummy = new ListNode(0, head);

//         /*
//          * prev:
//          * Points to node just before the current pair
//          * being swapped.
//          */
//         ListNode* prev = dummy;

//         /*
//          * temp1:
//          * First node of current pair
//          *
//          * temp2:
//          * Second node of current pair
//          */
//         ListNode* temp1 = head;
//         ListNode* temp2 = head->next;

//         /*
//          * Continue while a valid pair exists
//          *
//          * temp2 exists          -> second node exists
//          * temp2->next exists    -> future list connection safe
//          */
//         while(temp2 && temp2->next){

//             /*
//              * Preserve remaining list before modifying links
//              *
//              * Example:
//              * 1 -> 2 -> 3 -> 4
//              *           ^
//              *          fwd
//              */
//             ListNode* fwd = temp2->next;

//             /*
//              * Step 1:
//              * Connect first node to remaining list
//              *
//              * 1 -> 3
//              */
//             temp1->next = fwd;

//             /*
//              * Step 2:
//              * Reverse current pair
//              *
//              * 2 -> 1
//              */
//             temp2->next = temp1;

//             /*
//              * Step 3:
//              * Connect previous section to swapped pair
//              *
//              * prev -> 2 -> 1
//              */
//             prev->next = temp2;

//             /*
//              * Move pointers forward for next pair
//              */

//             // prev should now point to tail of swapped pair
//             prev = temp1;

//             // Move to next pair
//             temp1 = fwd;

//             // Second node of next pair
//             temp2 = temp1->next;
//         }

//         /*
//          * Handle final remaining pair
//          *
//          * This executes for last valid pair after loop exits
//          */
//         if(temp2){

//             // Connect first node to remaining list
//             temp1->next = temp2->next;

//             // Reverse pair
//             temp2->next = temp1;

//             // Attach swapped pair to previous section
//             prev->next = temp2;
//         }

//         // Return updated head (skip dummy node)
//         return dummy->next;
//     }
// };