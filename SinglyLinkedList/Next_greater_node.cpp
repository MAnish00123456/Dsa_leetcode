// You are given the head of a linked list with n nodes.
// For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.
// Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

// Input: head = [2,1,5]
// Output: [5,5,0]

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
//     ListNode* reverseList(ListNode* head){
//         ListNode* curr = head;
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
//         vector<int> nextLargerNodes(ListNode* head){
//             ListNode* newHead = reverseList(head);
//             stack<int>st;
//             ListNode* curr = newHead;
//             vector<int>Ans;
//             while(curr){
//                 while(!st.empty() && st.top() <= curr->val)st.pop();
                
//                 if(st.empty()){
//                     Ans.push_back(0);
//                 }else{
//                     Ans.push_back(st.top());
//                 }

//                 st.push(curr->val);
//                 curr = curr->next;
//             }
//             reverse(Ans.begin(),Ans.end());
//             return Ans;
//         }
// };