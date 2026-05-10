//given a head of linked list , the indexing starts from 1(assume) , so indice 1,3,5 are odd indices and 2,4,6 are even indices
//so modify the list inplace that all odd indices come first and even afterwards
//for ex : , original list = [1,2,3,4,5] and modifed list = [1,3,5,2,4]
//use 2 pointers odd at head and even at head->next ,.., preserve first even node of list
//manipulate using pointers

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
//     ListNode* oddEvenList(ListNode* head) {
//         if(!head || !head->next || !head->next->next)return head;
//         ListNode* odd = head;
//         ListNode* even = head->next;
//         ListNode* preserve_even_Node = even;
//         while(even && even->next){
//             odd->next = even->next;
//             odd=even->next;

//             even->next = odd->next;
//             even=odd->next;
//         }
//         odd->next=preserve_even_Node;
//         return head;
//     }
// };