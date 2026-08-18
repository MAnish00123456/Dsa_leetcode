// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
// Implement the LRUCache class:
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

// #include<iostream>
// #include<unordered_map>
// #include<functional>

// class DLLListNode {
//     public:
// int key;
// int val;
// DLLListNode* next;
// DLLListNode* prev;

// DLLListNode(int key , int val){
//     this -> key = key;
//     this -> val = val;
//     next = nullptr;
//     prev = nullptr; 
// }
// };
// //used lambda funtion just to learn how to use inline lambda funtions
// //just declared add / remove as member functions
// class LRUCache {
// std::unordered_map<int,DLLListNode*>CacheMap;//stores key and address of that node as value
// int capacity = 0;
// DLLListNode* head;
// DLLListNode* tail;

// public:
// std::function<void(DLLListNode*)> addNode;
// std::function<void(DLLListNode*)> removeNode;

// LRUCache(int capacity) {
//     this -> capacity = capacity;
//     head = new DLLListNode(-1,-1);
//     tail = new DLLListNode(-1,-1);

//     head->next = tail;
//     tail->prev = head;

//  addNode = [this](DLLListNode* node) -> void{
//     DLLListNode* fwd = head->next;
//     head->next = node;
//     node -> prev = head;
//     node -> next = fwd;
//     fwd->prev = node;
// };
// removeNode = [this](DLLListNode* node) -> void {
//     DLLListNode* prv = node -> prev;
//     DLLListNode* nxt = node -> next;
//     prv -> next = nxt;
//     nxt -> prev = prv;
//     node -> next = nullptr;
//     node -> prev = nullptr;
// };

// }

// int get(int key) {
//     if(CacheMap.find(key) == CacheMap.end()){
//         return -1;
//     }
//     DLLListNode* prioNode = CacheMap[key];
//     removeNode(prioNode);
//     addNode(prioNode);

//     return CacheMap[key]->val;
// }

// void put(int key, int value) {
//     if(CacheMap.find(key) != CacheMap.end()){
//         DLLListNode* prioNode = CacheMap[key];
//         removeNode(prioNode);
//         addNode(prioNode);
//         prioNode -> val = value;
//         return;
//     }
//     DLLListNode* newNode = new DLLListNode(key,value);
//     CacheMap[key] = newNode;
//     addNode(newNode);

//     if(CacheMap.size() > capacity){
//         DLLListNode* nodeTodelete = tail->prev;
//         removeNode(nodeTodelete);
//         CacheMap.erase(nodeTodelete->key);
//         delete nodeTodelete;
//     }
// }
// };
