//in this question we have given a linked list and we need to remove the middle node of the linked list and return the remaining list
//we  will take help of two pointers which are slow and fast 
//slow moves one step and fast moves 2 step ahead , we run the loop until our fast pointer reaches null
//when fast reaches null , our slow pointer will point towards middle of list

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
//     ListNode* deleteMiddle(ListNode* head) {
//         ListNode* dummy = new ListNode(0,head);
//         ListNode* slow = dummy;
//         ListNode* fast = head;
//         while(fast && fast->next){
//             slow = slow= slow->next;
//             fast = fast->next->next;
//         }
//         slow->next = slow->next->next;
//         return dummy->next;
//     }
// };