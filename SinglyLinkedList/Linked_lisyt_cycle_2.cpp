//given head of list , return the node at which cycle forms
//use of slow and fast pointers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* detectCycle(ListNode* head) {
//         if (!head)
//             return head;
//         ListNode* slow = head;
//         ListNode* fast = head;
//         bool isCycle = false;
//         while (fast && fast->next) {
//             slow = slow->next;
//             fast = fast->next->next;
//             if (slow == fast) {
//                 isCycle = true;
//                 break;
//             }
//         }
//         if (!isCycle)
//             return nullptr;
//         slow = head;
//         while (slow != fast) {
//             slow = slow->next;
//             fast = fast->next;
//         }
//         return slow;
//     }
// };