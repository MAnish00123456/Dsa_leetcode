// in this question we have been given a linked list and the nodes represemts a number such as 1 -> 2 -> 3-> 4, represents 1234
//we need to double this number and return the list , means  output : 1 -> 4 -> 9 -> 1 -> 6


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// #define ll long long

// class Solution {
// 
    // Helper function to reverse a linked list in-place
    // Used to process digits from least significant to most significant
    // ListNode* reverseList(ListNode* head) {
        // ListNode* prev = NULL;
        // ListNode* curr = head;

        // while (curr) {
            // ListNode* forward = curr->next; // store next node
            // curr->next = prev;              // reverse link
            // prev = curr;                   // move prev forward
            // curr = forward;                // move curr forward
        // }

        // 'prev' becomes the new head after reversal
//         return prev;
//     }

// public:
//     ListNode* doubleIt(ListNode* head) {

        // Step 1: Reverse the list
        // This allows us to process from least significant digit (like normal number multiplication)
        // ListNode* newHead = reverseList(head);

        // Step 2: Traverse reversed list and double each digit
        // Handle carry similar to elementary multiplication
        // ListNode* temp = newHead;
        // ll carry = 0;

        // while(temp){
        //     ll data = temp->val;

            // Multiply current digit by 2 and add carry
            // data = data * 2 + carry;

            // Store the unit digit back in node
            // temp->val = data % 10;

            // Update carry for next node
            // carry = data / 10;

            // Move to next node
        //     temp = temp->next;
        // }

        // Step 3: Reverse the list again to restore original order
        // ListNode* oldhead = reverseList(newHead);

        // Step 4: If there is remaining carry,
        // create a new node at the front
        // if(carry != 0){
        //     ListNode* carryNode = new ListNode(carry);

            // Attach carry node before current head
            // carryNode->next = oldhead;

            // Update head to new node
        //     oldhead = carryNode;
        // }

        // Return final updated list
//         return oldhead;
//     }
// };