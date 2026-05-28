#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
    
            /*
            ------------------------------------------------------------
            PROBLEM:
            Remove the nth node from the end of the linked list.
    
            ------------------------------------------------------------
            IDEA:
            Use TWO POINTERS (left & right) with a gap of n nodes.
    
            Step 1:
            Move 'right' pointer n steps ahead.
    
            Step 2:
            Move both 'left' and 'right' together
            until 'right' reaches the end.
    
            At this point:
            → 'left' will be exactly before the node to delete.
    
            ------------------------------------------------------------
            WHY DUMMY NODE?
    
            Example:
            head = [1,2,3], n = 3
    
            We need to delete the HEAD.
            Without dummy, it's messy.
    
            Dummy simplifies:
            dummy → 1 → 2 → 3
            */
    
            if(head == NULL) return head;
    
            ListNode* dummy = new ListNode(0, head);
    
            // left starts from dummy (important for deleting head)
            ListNode* left = dummy;
    
            // right starts from actual head
            ListNode* right = head;
    
            /*
            Move right pointer n steps ahead
            → creates a gap of n nodes between left and right
            */
            while(n > 0 && right != NULL){
                right = right->next;
                n--;
            }
    
            /*
            Move both pointers until right reaches NULL
    
            At this point:
            → left is just before the node we need to delete
            */
            while(right != NULL){
                left = left->next;
                right = right->next;
            }
    
            /*
            Delete node:
            left → node_before_target
            left->next → target node
            */
            ListNode* prev = left->next;
    
            // bypass target node
            left->next = left->next->next;
    
            // disconnect and delete node to avoid memory leak
            prev->next = NULL;
            delete prev;
    
            /*
            Return new head (could be different if original head deleted)
            */
            return dummy->next;
        }
    };
    
    // 🔧 Helper: create linked list from array
    ListNode* createList(int arr[], int n) {
        if(n == 0) return nullptr;
    
        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;
    
        for(int i = 1; i < n; i++){
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
    
        return head;
    }
    
    
    // 🔧 Helper: print linked list
    void printList(ListNode* head) {
        while(head){
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "NULL\n";
    }
    
    
    int main() {
    
        int arr[] = {1,2,3,4,5};
        int n = sizeof(arr)/sizeof(arr[0]);
    
        ListNode* head = createList(arr, n);
    
        cout << "Original: ";
        printList(head);
    
        Solution sol;
        head = sol.removeNthFromEnd(head, 2);
    
        cout << "After deletion: ";
        printList(head);
    
        return 0;
    }