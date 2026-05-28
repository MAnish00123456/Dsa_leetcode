// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.


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
//     ListNode* deleteDuplicates(ListNode* head) {
//         if(!head || !head->next)return head;
//         ListNode* prev = nullptr;
//         ListNode* curr = head;
//         while(curr){
//             if(curr == head){
//                 prev = curr;
//                 curr = curr->next;
//             }else{
//                 if(curr->val == prev->val){
//                     prev->next = curr->next;
//                     ListNode* temp = curr;
//                     curr = curr->next;
//                     temp->next = nullptr;
//                     delete temp;
//                 }else{
//                     prev = curr;
//                     curr = curr->next;
//                 }
//             }
//         }
//         return head;
//     }
// };