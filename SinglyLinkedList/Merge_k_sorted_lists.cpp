// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6

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
//     ListNode* mergeKLists(vector<ListNode*>& lists) {

//         //use of maxHeap to store all node values of all lists 
//         priority_queue<int> pq;
//         for(ListNode* head : lists){
//             if(head == nullptr)continue;

//             ListNode* temp = head;

//             while(temp){
//                 //storing values by negation makes maximum value minimum and gets stored in child node , so that root contains min element , acts as a Min heap
//                 pq.push((-1)*temp->val);
//                 temp=temp->next;
//             }

//         }

//         //creates a new list by traversing priority queue
//         ListNode* dummy = new ListNode(0);
//         ListNode* temp = dummy;
//         while(!pq.empty()){
//             int val = pq.top() * (-1);
//             ListNode* newNode = new ListNode(val);
//             temp->next = newNode;
//             temp = newNode;
//             pq.pop();
//         }
//         return dummy->next;
//     }
// };