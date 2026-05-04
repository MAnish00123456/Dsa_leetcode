// // This function reverses a portion of the linked list from position 'left' to 'right'
// ListNode* reverseBetween(ListNode* head, int left, int right) {

//     // Edge case: empty list
//     if (!head) return head;

//     // Dummy node helps handle edge cases like reversing from head (left = 1)
//     ListNode* dummy = new ListNode(0, head);

//     // Step 1: Move to node just before the 'left' position
//     ListNode* temp1 = dummy;
//     for (int i = 0; i < left - 1; i++) {
//         temp1 = temp1->next;
//     }

//     // Step 2: Initialize pointers for reversal
//     ListNode* prev = NULL;
//     ListNode* curr = temp1->next;

//     // This node will become the tail of the reversed segment
//     // and will later connect to the remaining list
//     ListNode* preserveNode = curr;

//     int st = left;

//     // Step 3: Reverse nodes from left to right
//     while (curr && st != right + 1) {
//         ListNode* forward = curr->next; // store next node
//         curr->next = prev;              // reverse link
//         prev = curr;                    // move prev forward
//         curr = forward;                 // move curr forward
//         st++;
//     }

//     // Step 4: Reconnect reversed part back to list

//     // Connect node before 'left' to new head of reversed segment
//     temp1->next = prev;

//     // Connect tail of reversed segment to remaining list
//     if (curr) {
//         preserveNode->next = curr;
//     }

//     // Return new head (skip dummy)
//     return dummy->next;
// }