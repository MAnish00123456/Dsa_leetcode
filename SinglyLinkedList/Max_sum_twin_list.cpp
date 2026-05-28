// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.
// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

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
//     int pairSum(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head;
//         ListNode* prev = nullptr;
//         // first find middle and middle - 1 node
//         while (fast && fast->next) {
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         prev->next = nullptr; // first half of list
//         ListNode* prev1 = nullptr;
//         ListNode* curr = slow;
//         // reverse second half
//         while (curr) {
//             ListNode* fwd = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = fwd;
//         }

//         // now both lists are ready to get traversed according to our question
//         ListNode* temp1 = head;
//         ListNode* temp2 = prev;
//         int maxSum = INT_MIN;
//         while (temp1 && temp2) {
//             if (temp1->val + temp2->val > maxSum)
//                 maxSum = temp1->val + temp2->val;
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//         }
//         return maxSum;
//     }
// };