// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the LFUCache class:

// LFUCache(int capacity) Initializes the object with the capacity of the data structure.
// int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
// void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

// The functions get and put must each run in O(1) average time complexity.

// Input
// ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, 3, null, -1, 3, 4]

// Explanation
// // cnt(x) = the use counter for key x
// // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
// LFUCache lfu = new LFUCache(2);
// lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
// lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
// lfu.get(1);      // return 1
//                  // cache=[1,2], cnt(2)=1, cnt(1)=2
// lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
//                  // cache=[3,1], cnt(3)=1, cnt(1)=2
// lfu.get(2);      // return -1 (not found)
// lfu.get(3);      // return 3
//                  // cache=[3,1], cnt(3)=2, cnt(1)=2
// lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
//                  // cache=[4,3], cnt(4)=1, cnt(3)=2
// lfu.get(1);      // return -1 (not found)
// lfu.get(3);      // return 3
//                  // cache=[3,4], cnt(4)=1, cnt(3)=3
// lfu.get(4);      // return 4
//                  // cache=[4,3], cnt(4)=2, cnt(3)=3

// class DLLNode{
//     public:
//         int key , value , cnt ;
//         DLLNode* next , *prev;
//         DLLNode(int key , int value){
//             this -> key = key;
//             this -> value = value;
//             cnt = 1;//each new node occurs atleast once , so freq count = 1
//             next = nullptr;
//             prev = nullptr;
//         }   
// };

// class LFUCache {
//     unordered_map<int,DLLNode*>CacheMap;//Maps key -> node , to access the node in O(1) time
//     unordered_map<int,pair<DLLNode*,DLLNode*>>FreqMap;//current minfreq -> corresponding doubly linked list head and tail
//     //we create different DLL and each DLL corresponds to a frequency number and we shift nodes and remove nodes from the lists according to the frequency
//     int capacity;
//     int minFreq;

//     void add(DLLNode* node , int freq){
//         //to add node to a already made DLL with a frequency number or to create a new DLL for given frequency
//         if(FreqMap.find(freq) == FreqMap.end()){
//             DLLNode* head = new DLLNode(-1,-1);
//             DLLNode* tail = new DLLNode(-1,-1);
//             head -> next = tail;
//             tail -> prev = head;

//             FreqMap[freq] = {head,tail};
//         }
// //new nodes or current accessed nodes are always  added to head of DLL , having high priority
//         DLLNode* head = FreqMap[freq].first;
//         DLLNode* fwd = head->next;
//         head -> next = node;
//         node -> next = fwd;
//         fwd -> prev = node;
//         node -> prev = head;
//     }
// //Nodes that are near the tail node are removed whenever capcity gets full
//     void remove(DLLNode* node){
//         DLLNode* fwd = node -> next;
//         DLLNode* prv = node -> prev;

//         prv -> next = fwd;
//         fwd -> prev = prv;

//         node -> next = nullptr;
//         node -> prev = nullptr;
//     }
// //whenever a node is accessed , we increase the frequency count of the node and shifts its location to corresponding DLL for the updated frequency
//     void updateFreq(DLLNode* node){
//         int oldFreq = node ->cnt;
//         node -> cnt = oldFreq + 1;

//         remove(node);

//         if(FreqMap[oldFreq].first->next == FreqMap[oldFreq].second){
//             FreqMap.erase(oldFreq);
//             if(oldFreq == minFreq){
//                 minFreq += 1;
//             }
//         }
//         add(node,node -> cnt);
//     }
// public:
//     LFUCache(int capacity) {
//         this -> capacity = capacity;
//         minFreq = 0;
//     }
    
//     int get(int key) {
//         if(CacheMap.find(key) == CacheMap.end())return -1;
//         DLLNode* node = CacheMap[key];
//         int res = node -> value;
//         //updates node frequency whenever it is accessed
//         updateFreq(node);
//         return res;
//     }
    
//     void put(int key, int value) {
//         if(capacity == 0)return;
// //if current key,val node exists , simply update the value for the key node and update its frequency count to shift it to new DLL
//         if(CacheMap.find(key) != CacheMap.end()){
//             DLLNode* node = CacheMap[key];
//             node -> value = value;
//             updateFreq(node);
//             return;
//         }
// //if capacity is full , remove the least used node , i.e ,the node just before tail pointer for current minFreq
//         if(capacity == CacheMap.size()){
//             DLLNode* nodeTodelete = FreqMap[minFreq].second->prev;
//             CacheMap.erase(nodeTodelete -> key);
//             remove(nodeTodelete);
//             if(FreqMap[minFreq].first->next == FreqMap[minFreq].second){
//                 FreqMap.erase(minFreq);
//                 minFreq++;
//             }
//             delete nodeTodelete;
//         }
// //add new key,value node to map and list and update minFreq back to 1
//         DLLNode* newNode = new DLLNode(key,value);
//         CacheMap[key] = newNode;
//         minFreq = 1;
//         add(newNode,1);
//     }
// };

