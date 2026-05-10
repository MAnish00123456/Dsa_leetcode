//given a head of a linked list , manipulate it according  to given description

//You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln

// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

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
//     //find middle node of the linked list
//     ListNode* middleLinkedList(ListNode* head,ListNode* &prevNode){
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast && fast->next){
//             prevNode = slow;
//             slow = slow->next;
//             fast  = fast->next->next;
//         }
//         return slow;
//     }
//     //reverse the second half of linked list means from middleNode to end
//     ListNode* reverseList(ListNode* curr){
//         ListNode* prev = nullptr;
//         while(curr){
//             ListNode* fwd = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = fwd;
//         }
//         return prev;
//     }
// public:
//     void reorderList(ListNode* head) {
//         //case when list have only 1 node or is empty
//         if(!head || !head->next) return ;

//         ListNode* prevNode = nullptr;//will store a node just before our middle node

//         ListNode* middleNode = middleLinkedList(head,prevNode);//store middle node of list

//         ListNode* reverseListHead = reverseList(middleNode);//reverse second half

//         prevNode->next = nullptr;

//         ListNode* temp1 = head;//used to traverse first half

//         ListNode* temp2 = reverseListHead;//used to traverse second half

//         while(temp1 && temp2 && temp1->next && temp2->next){

//             ListNode* fwd1 = temp1->next;
//             ListNode* fwd2 = temp2->next;

//             //pointer manipulation according to the question
//             temp1->next = temp2;
//             temp2->next = fwd1;

//             temp1 = fwd1;
//             temp2 = fwd2;
//         }
        
//         if(!temp1->next){
//             temp1->next = temp2;
//         }

//     }
// };

/*
lets dry run an example : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
middleNode = 4
reverseList = 7 -> 6 -> 5 -> 4
updated lists: 1 -> 2 -> 3 -> null  ,,, 7 -> 6 -> 5 -> 4 -> null
now manipulate both lists and list will become
1 -> 7 -> 2 -> 6 -> 3 -> 5 -> 4
*/