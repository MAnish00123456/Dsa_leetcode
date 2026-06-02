// You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

// Input: nums = [1,2,3], head = [1,2,3,4,5]

// Output: [4,5]
 

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
//     ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//      bool seen[100'001] = {false};
//      for(int val : nums)seen[val]=true;

//      ListNode* dummy = new ListNode(0,head);
//      ListNode* prev = dummy;
//      ListNode* curr  = head;
//      while(curr){
//         if(seen[curr->val]){
//             curr = curr->next;
//         }else{
//             prev->next = curr;
//             prev = curr;
//             curr = curr->next;
//         }
//      }    
//      if(prev->next && seen[prev->next->val])prev->next = nullptr;
//      return dummy->next;
//     }
// };