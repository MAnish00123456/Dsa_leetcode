// Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }

// Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
// Explanation: There are 4 nodes in the graph.
// 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         //mark old node values to new node values in hashmap
//         //recursively deep dive in each neighbor for every single node and build up neighbor list and return new node at last

//         unordered_map<Node*,Node*>oldTonew;

//         auto dfs = [&](auto&&self , Node* node)->Node*{
//             //return new copy of the given node , if already exist
//             if(oldTonew.count(node)){
//                 return oldTonew[node];
//             }
//             if(!node)return nullptr;
//             //else make new copy with given node val and store it in hashmap
//             Node* newNode = new Node(node->val);
//             oldTonew[node] = newNode;
//             //recusively go to each neighbor , get their corresponding newNode copies and store in current node neighbors list
//             for(auto& ngbr : node->neighbors){
//                 newNode->neighbors.push_back(self(self,ngbr));
//             }
//             return newNode;
//         };

//         return dfs(dfs,node);

//     }
// };