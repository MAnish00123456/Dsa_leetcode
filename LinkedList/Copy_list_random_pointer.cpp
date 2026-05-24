// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/



// class Solution {
// public:
//     Node* copyRandomList(Node* head) {

//         /*
//             Edge case:
//             If original list is empty,
//             copied list should also be empty.
//         */
//         if (!head) return nullptr;

//         /*
//             HashMap stores mapping:

//             Original Node  -> Copied Node

//             This helps us quickly connect random pointers
//             without searching entire copied list.

//             Example:

//             Original:
//             A -> B -> C

//             Map:
//             A -> A'
//             B -> B'
//             C -> C'
//         */
//         unordered_map<Node*, Node*> Map;

//         /*
//             Create first node separately.

//             We immediately store mapping so that
//             future random pointer assignments become easy.
//         */
//         Node* newHead = new Node(head->val);
//         Map[head] = newHead;

//         /*
//             oldtemp traverses original list
//             newtemp builds copied list
//         */
//         Node* oldtemp = head->next;
//         Node* newtemp = newHead;

//         /*
//             First Pass:

//             Create duplicate nodes and connect
//             only NEXT pointers.

//             Example:

//             Original:
//             7 -> 13 -> 11

//             Copy after first pass:
//             7' -> 13' -> 11'

//             Random pointers remain unassigned.
//         */
//         while (oldtemp) {

//             Node* newNode = new Node(oldtemp->val);

//             // Store original -> copied mapping
//             Map[oldtemp] = newNode;

//             // Connect copied list
//             newtemp->next = newNode;

//             // Move both pointers forward
//             newtemp = newtemp->next;
//             oldtemp = oldtemp->next;
//         }

//         /*
//             Second Pass:

//             Assign RANDOM pointers.

//             Since every original node already has
//             a copied version stored inside hashmap,
//             random connection becomes O(1).

//             Example:

//             Original:
//             A.random -> C

//             Copy:
//             A'.random -> C'
//         */
//         newtemp = newHead;
//         oldtemp = head;

//         while (newtemp && oldtemp) {

//             /*
//                 oldtemp->random gives original target node

//                 Map[...] gives corresponding copied node
//             */
//             newtemp->random = Map[oldtemp->random];

//             newtemp = newtemp->next;
//             oldtemp = oldtemp->next;
//         }

//         /*
//             Deep copied linked list completed.

//             Time Complexity: O(N)
//             Space Complexity: O(N)
//             (HashMap stores N node mappings)
//         */
//         return newHead;
//     }
// };