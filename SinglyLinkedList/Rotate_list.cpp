// Given the head of a linked list, rotate the list to the right by k places.


/**
 * Rotate the linked list to the right by k positions.
 * 
 * Idea:
 * Instead of shifting nodes one by one, we:
 * 1. Convert the list into a circular linked list.
 * 2. Find the new tail position.
 * 3. Break the circle to form the rotated list.
 */

// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {

//         // Edge cases:
//         // - empty list
//         // - single node
//         // - no rotation needed
//         if(!head || !head->next || k == 0) return head;

//         // Step 1: Find length of the list
//         int n = 1;                  // start with 1 (we are at head)
//         ListNode* temp = head;

//         while(temp->next){
//             temp = temp->next;
//             n++;
//         }

//         // Step 2: Make the list circular
//         // tail → head connection
//         temp->next = head;

//         // Step 3: Normalize k
//         // rotating n times gives same list
//         k = k % n;

//         // Step 4: Find new tail
//         // new tail is at position (n - k)
//         int steps = n - k;

//         ListNode* newtail = head;

//         // move to (n - k - 1)-th node (1-based logic)
//         for(int i = 1; i < steps; i++){
//             newtail = newtail->next;
//         }

//         // Step 5: Set new head
//         ListNode* newhead = newtail->next;

//         // Step 6: Break the circular link
//         newtail->next = nullptr;

//         return newhead;
//     }
// };