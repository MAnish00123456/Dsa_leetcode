// You are given the head of a linked list.
// The nodes in the linked list are sequentially assigned to non-empty groups whose lengths form the sequence of the natural numbers (1, 2, 3, 4, ...). The length of a group is the number of nodes assigned to it. In other words,
// The 1st node is assigned to the first group.
// The 2nd and the 3rd nodes are assigned to the second group.
// The 4th, 5th, and 6th nodes are assigned to the third group, and so on.
// Note that the length of the last group may be less than or equal to 1 + the length of the second to last group.
// Reverse the nodes in each group with an even length, and return the head of the modified linked list.


//main intution is that ,if current part have even nodes then reverse it and if dont then dont


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
//     ListNode* reverseEvenLengthGroups(ListNode* head) {
//         if(!head->next) return head;//return if only 1 node present

//         ListNode* dummy = new ListNode(0,head);
//         //prev1 will become tail of the current part
//         ListNode* prev1 = nullptr;
//         //count store count of nodes in each part
//         int count;
//         //preserveNode stores the last node of previous part , for reconnection when reversal happens
//         ListNode* preserveNode = dummy;
//         //temp traverse whole list and count no of nodes in each part
//         ListNode* temp = head;
//         //curr stores the current part head , which can become tail if reversal happens
//         ListNode* curr = head;
//         //traverse ove list and take 'i' as part number starting from 1
//         for(int i = 1 ; curr ; i++){
//             //prev helps only during reversal
//             ListNode* prev = nullptr;
//             //reset count to 0 , for each part
//             count = 0;
//             //traverse current part and count number of nodes
//             while(count < i && temp){
//                 count++;
//                 //upate tail of the part till part exists so that it will store last node of the currnt part when current part counting is over
//                 prev1 = temp;
//                 temp = temp->next;
//             }
//             //if count of nodes in currrent part is even
//             if(count % 2 == 0){
//                 //stores the head node of the current part which is abt to get reversed
//                 ListNode* Nodehead = curr;
//                 //inplace traversal of nodes , performed for only count nodes of the current part
//                 while(curr && count){
//                     ListNode* fwd = curr->next;
//                     curr->next = prev;
//                     prev = curr;
//                     curr = fwd;
//                     count--;
//                 }
//                 //now after traversal our last part last node points to our current part first node after reversal 
//                 preserveNode->next = prev;
//                 //our current part old head now points to our next part head node
//                 Nodehead->next = curr;
//                 //preserve node now points to our last node of the current reversed part
//                 preserveNode = Nodehead;
//             }
//             //if count of nodes is not even in current part , we will completely skip the whole part to process next part
//             else{
//                 //curr points to our new part 1st node which will become headnode of new part
//                 curr = temp;
//                 //preserve node points to our last part tail node
//                 preserveNode = prev1;
//             }
//         }
//         return dummy->next;
//     }
// };