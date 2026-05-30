// You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.
// Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.

// Input: head = [0,1,2,3], nums = [0,1,3]
// Output: 2

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
//     int numComponents(ListNode* head, vector<int>& nums) {
//         if(nums.size() < 2)return 1;
//         unordered_set<int>Hashset(nums.begin(),nums.end());
      
//         ListNode* curr = head;
//         int count = 0;
//                 while(curr != nullptr){
//             if(Hashset.count(curr->val) && (curr->next == nullptr || !Hashset.count(curr->next->val))){
//             count++;
//             }
//                 curr=curr->next;
//         }
//         return count;
//     }
// };