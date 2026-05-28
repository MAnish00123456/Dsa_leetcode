// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.

 
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

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
// int sizeOfList(ListNode* head){
//     int n = 0;
//     ListNode*temp= head;
//     while(temp){
//         n++;
//         temp=temp->next;
//     }
//     return n;
// }
// public:

//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(!head->next)return head;
//         //calculate total nodes in list
//         int n = sizeOfList(head);
//         //create a dummy node and store address of head , helps in cases when reversing original head
//         ListNode* dummy = new ListNode(0,head);
//         //initially prev points to dummy , so as to update the head later on
//         ListNode* prev = dummy;
//         //temp is used in reversal 
//         ListNode* temp = nullptr;
//         //curr node to traverse list
//         ListNode* curr = head;

// //count no of times we have to reverse the list , or we can say valid no of count for which we can reverse nodes in  k groups
// //for ex , n = 5 , k = 2 , process = 5/2 == 2 times we will have to reverse nodes in k groups
//         int process = n/k;

//         while(process > 0){
//             //preserve our curr node as it will become our new tail for current batch of reversal group
//             ListNode* preserveNode = curr;

// //reverse nodes inplace
//             for(int i = 0 ; i < k ; i++){
//                 ListNode* fwd = curr->next;
//                 curr->next = temp;
//                 temp = curr;
//                 curr = fwd;
//             }

// //point our newtail to connect to remaining list
//             preserveNode->next = curr;
//             // Connect previous processed section to newly reversed k-group
//             prev->next = temp;
// // Shift prev to current group's tail for next connection
//             prev = preserveNode;
//             //reset temp again for new geoup reversal
//             temp = nullptr;


//     //decrease the count of reversal groups
//             process--;
//         }
//         //return new list head
//         return dummy->next;
//     }
// };