//in this question whether a linked list is palindrome or not
//we will first find middle of linked list and after that we will reverse our linked list from middle node to end
//then traverse starting half list and other half list and compare values for palindrome

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
// public:
//     bool isPalindrome(ListNode* head) {
//         if(!(head) || !(head->next)) return true;
//         ListNode* fast = head;
//         ListNode* slow = head;

//         //find middle element (slow point towards it) of list using fast and slow pointers
//         //slow moves one step and fast moves two step
//         while(fast && fast->next){
//             fast = fast->next->next;
//             slow= slow->next;
//         }

//         //reverse list from slow to end
//         ListNode* prev = NULL;
//         while(slow){
//             ListNode* forward = slow->next;
//             slow->next = prev;
//             prev = slow;
//             slow = forward;
//         }
//     ListNode* temp = head;
//     ListNode* temp1 = prev;
//     //compare values of first and second half
//         while(temp && temp1){
//             if(temp->val != temp1->val){
//                 return false;
//             }
//             temp=temp->next;
//             temp1=temp1->next;
//         }
// return true;
//     }
// };
