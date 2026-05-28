//given 2 list , values in reversed order , return the sum of the values formed by both lists
//for ex : l1 = 2->4->3 ; l2 = 5->6->4
//resultant node = 7->0->8

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 * };
 */

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

//         // Edge cases: if one list is empty, return the other
//         if(!l1) return l2;
//         if(!l2) return l1;

//         // Dummy node helps simplify list construction
//         // Avoids special handling for head
//         ListNode* dummy = new ListNode(0);
//         ListNode* curr = dummy;

//         int carry = 0; // stores carry from previous digit addition

//         // Traverse both lists until both are exhausted AND no carry remains
//         while(l1 || l2 || carry){

//             int sum = carry; // start with carry

//             // Add value from first list (if available)
//             if(l1){
//                 sum += l1->val;
//                 l1 = l1->next;
//             }

//             // Add value from second list (if available)
//             if(l2){
//                 sum += l2->val;
//                 l2 = l2->next;
//             }

//             // Create new node with unit digit of sum
//             curr->next = new ListNode(sum % 10);

//             // Update carry (tens digit)
//             carry = sum / 10;

//             // Move current pointer forward
//             curr = curr->next;
//         }

//         // Return result list (skip dummy node)
//         return dummy->next;
//     }
// };

//add 2 numbers 2 (445)
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
// class Solution {
//     ListNode* reverseList(ListNode* head){
//         ListNode* curr = head;
//         ListNode* prev = nullptr;
//         while(curr){
//             ListNode* forward = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = forward;
//         }
//         return prev;
//     }
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         if(!l1) return l2;
//         if(!l2) return l1;

//         ListNode* newl1 = reverseList(l1);
//         ListNode* newl2 = reverseList(l2);

//         ListNode* dummy = new ListNode(0);
//         ListNode* temp = dummy;

//         int carry = 0;

//         while(newl1 || newl2 || carry){
//             int sum = carry;

//             if(newl1){
//                 sum+=newl1->val;
//                 newl1= newl1->next;
//             }

//             if(newl2){
//                 sum+=newl2->val;
//                 newl2 = newl2->next;
//             }

//             temp->next = new ListNode(sum%10);
//             carry = sum / 10;
//             temp = temp->next;
//         }
//         return reverseList(dummy->next);
//     }
// };
