// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
//for ex : 1->2->2->3->3->4 would become , 1-> 4


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
//         if(!head || !head->next) return head;
//         //dummy node to handle cases where we need to shift our head node because it was appearing more than once
//         ListNode* dummy = new ListNode(0,head);

//         ListNode* prev = dummy;//to point towards a unique node which was not duplicated with its adjacent node

//         ListNode* curr = head;//current node in list

//         ListNode* fwd = curr->next;//node next to curr , used for duplicacy check

//         bool  isduplicate = false;//to keep a track whether we need to move our prev pointer or just update prev->next
//         //if adjacent duplicates are found we will only update prev->next as prev points to a confirmed unique node
//         //else if there are no adjacent duplicates like , 1->1->2->3->3 , our prev->next will point to node with value 2 , because it is an unique node and our prev node will become this node
//         while(fwd){
//             //skip multiple blocks with fwd pointer unless we reach a node which is not duplicated with curr node
//             while(fwd && fwd->val == curr->val){
//                 isduplicate = true;//to see that duplicates are present
//                 fwd = fwd->next;
//             }
//             //only moving prev pointer when it is confirmed that there were no duplicates and we have a unique node
//             if(!isduplicate){
//             prev = curr;
//             curr = fwd;//curr moves to next candidate group
//             fwd =fwd? fwd->next:nullptr;
//             }
//             //only updating prev->next if there were multiple adjacent duplicate nodes with same value
//             else{
//                 prev->next = fwd;
//                 curr=fwd;
//                 fwd=fwd?fwd->next:nullptr;
//                 isduplicate = false;
//             }
//         }
//         return dummy->next;
//     }
// };