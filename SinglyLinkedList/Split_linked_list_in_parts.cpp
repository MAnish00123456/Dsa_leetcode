// Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
// The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
// The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
// Return an array of the k parts.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 * };
 */

// class Solution {

//     /*
//      * Function to calculate size of linked list
//      *
//      * Time Complexity: O(n)
//      */
//     int SizeofList(ListNode* head){

//         int n = 0;
//         ListNode* temp = head;

//         // Traverse list and count nodes
//         while(temp){
//             n++;
//             temp = temp->next;
//         }

//         return n;
//     }

// public:
//     vector<ListNode*> splitListToParts(ListNode* head, int k) {

//         /*
//          * Edge case:
//          * Empty list with one required part
//          */
//         if(!head && k == 1) return {nullptr};

//         // Total number of nodes in linked list
//         int n = SizeofList(head);

//         /*
//          * First (n % k) parts will contain:
//          * (n/k + 1) nodes
//          *
//          * Remaining parts will contain:
//          * (n/k) nodes
//          *
//          * This ensures parts differ in size by at most 1.
//          */
//         int firstParts = n % k;

//         /*
//          * nextParthead:
//          * Tracks starting node of upcoming partition
//          */
//         ListNode* nextParthead = head;

//         /*
//          * prevPartHead:
//          * Stores head of current partition
//          */
//         ListNode* prevPartHead = nextParthead;

//         /*
//          * prevPartTail:
//          * Stores tail node before disconnecting current part
//          */
//         ListNode* prevPartTail = nullptr;

//         // Stores answer partitions
//         vector<ListNode*> Ans;

//         /*
//          * Process larger partitions first
//          * (parts having one extra node)
//          */
//         while(firstParts && nextParthead){

//             // Size of current partition
//             int minElems = n/k + 1;

//             /*
//              * Traverse current partition
//              * until required size is reached
//              */
//             while(minElems && nextParthead){

//                 prevPartTail = nextParthead;

//                 nextParthead = nextParthead
//                                ? nextParthead->next
//                                : nullptr;

//                 minElems--;
//             }

//             /*
//              * Disconnect current partition
//              */
//             prevPartTail->next = nullptr;

//             // Store current partition head
//             Ans.push_back(prevPartHead);

//             // Move to next partition
//             prevPartHead = nextParthead;

//             firstParts--;
//         }

//         /*
//          * Reset tail pointer for remaining partitions
//          */
//         prevPartTail = nullptr;

//         /*
//          * Remaining partitions contain equal smaller size
//          */
//         int remainParts = k - n % k;

//         while(remainParts){

//             /*
//              * If list nodes are exhausted,
//              * remaining parts become nullptr
//              */
//             if(!nextParthead){

//                 Ans.push_back(nullptr);

//             }else{

//                 // Size of smaller partitions
//                 int minElems = n/k;

//                 /*
//                  * Traverse current partition
//                  */
//                 while(minElems && nextParthead){

//                     prevPartTail = nextParthead;

//                     nextParthead = nextParthead
//                                    ? nextParthead->next
//                                    : nullptr;

//                     minElems--;
//                 }

//                 /*
//                  * Disconnect current partition
//                  */
//                 prevPartTail->next = nullptr;

//                 // Store partition head
//                 Ans.push_back(prevPartHead);

//                 // Move to next partition
//                 prevPartHead = nextParthead;
//             }

//             remainParts--;
//         }

//         // Return all partitions
//         return Ans;
//     }
// };