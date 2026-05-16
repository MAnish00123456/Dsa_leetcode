//given 2 unsorted list , sort them in ascending order 
// we will take help of merge sort to perform this sorting

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
//     ListNode* mergeList(ListNode* l1 , ListNode* l2){
//         if(l1 == NULL || l2 == NULL)return l1?l1:l2;
//         ListNode* dummy = new ListNode(0);
//         ListNode* curr = dummy;
//         while(l1 && l2){
//             if(l1->val <= l2->val){
//                 curr->next = l1;
//                 curr = curr->next;
//                 l1=l1->next;
//             }
//             else{
//                 curr->next = l2;
//                 curr = curr->next;
//                 l2=l2->next;
//             }
//         }
//         curr->next = l1?l1:l2;
//         return dummy->next;
//     }
// public:
//     ListNode* sortList(ListNode* head) {
//         if(!head || !head->next)return head;

//         ListNode* slow = head;
//         ListNode* fast = head;
//         ListNode* mid = nullptr;
//         while(fast && fast->next){
//                 mid = slow;
//                 slow = slow->next;
//                 fast = fast->next->next;
//         }
//         mid->next = nullptr;
//         ListNode* l1 = sortList(head);
//         ListNode* l2 = sortList(slow);

//         return mergeList(l1,l2);
//     }
// };