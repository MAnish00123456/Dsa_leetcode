// Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

// Implement the AllOne class:

// AllOne() Initializes the object of the data structure.
// inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
// dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
// getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
// getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
// Note that each function must run in O(1) average time complexity.
// Input
// ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
// [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
// Output
// [null, null, null, "hello", "hello", null, "hello", "leet"]

// Explanation
// AllOne allOne = new AllOne();
// allOne.inc("hello");
// allOne.inc("hello");
// allOne.getMaxKey(); // return "hello"
// allOne.getMinKey(); // return "hello"
// allOne.inc("leet");
// allOne.getMaxKey(); // return "hello"
// allOne.getMinKey(); // return "leet"

//learnt soln


// class AllOne {
// private:
//     // A Bucket represents a single frequency tier
//     struct Bucket {
//         int freq;
//         unordered_set<string> keys;
//         Bucket* prev;
//         Bucket* next;
        
//         Bucket(int f) : freq(f), prev(nullptr), next(nullptr) {}
//     };

//     Bucket* head; // Dummy head for the bucket list
//     Bucket* tail; // Dummy tail for the bucket list
    
//     // Maps each key to the specific Bucket it currently belongs to
//     unordered_map<string, Bucket*> keyToBucket;

//     // Helper function to insert a new bucket right after an existing bucket
//     Bucket* createBucketAfter(Bucket* position, int freq) {
//         Bucket* newBucket = new Bucket(freq);
//         Bucket* nextBucket = position->next;
        
//         position->next = newBucket;
//         newBucket->prev = position;
//         newBucket->next = nextBucket;
//         nextBucket->prev = newBucket;
        
//         return newBucket;
//     }

//     // Helper function to safely delete an empty bucket from the chain
//     void removeBucketIfEmpty(Bucket* bucket) {
//         if (bucket->keys.empty() && bucket != head && bucket != tail) {
//             bucket->prev->next = bucket->next;
//             bucket->next->prev = bucket->prev;
//             delete bucket;
//         }
//     }

// public:
//     AllOne() {
//         head = new Bucket(0);
//         tail = new Bucket(0);
//         head->next = tail;
//         tail->prev = head;
//     }
    
//     void inc(string key) {
//         // Case 1: Key does not exist yet
//         if (keyToBucket.find(key) == keyToBucket.end()) {
//             // Check if a bucket for frequency 1 already exists right after head
//             if (head->next == tail || head->next->freq != 1) {
//                 createBucketAfter(head, 1);
//             }
//             head->next->keys.insert(key);
//             keyToBucket[key] = head->next;
//         } 
//         // Case 2: Key already exists
//         else {
//             Bucket* currBucket = keyToBucket[key];
//             int nextFreq = currBucket->freq + 1;
            
//             // Check if the next sequential frequency bucket already exists
//             if (currBucket->next == tail || currBucket->next->freq != nextFreq) {
//                 createBucketAfter(currBucket, nextFreq);
//             }
            
//             // Move the key up to the next bucket
//             currBucket->next->keys.insert(key);
//             keyToBucket[key] = currBucket->next;
            
//             // Clean up old bucket spot
//             currBucket->keys.erase(key);
//             removeBucketIfEmpty(currBucket);
//         }
//     }
    
//     void dec(string key) {
//         if (keyToBucket.find(key) == keyToBucket.end()) return;
        
//         Bucket* currBucket = keyToBucket[key];
//         int prevFreq = currBucket->freq - 1;
        
//         // Case 1: Frequency drops down to 0 (Remove completely)
//         if (prevFreq == 0) {
//             keyToBucket.erase(key);
//         } 
//         // Case 2: Move down to the previous frequency bucket
//         else {
//             // Check if the previous frequency bucket exists right behind it
//             if (currBucket->prev == head || currBucket->prev->freq != prevFreq) {
//                 createBucketAfter(currBucket->prev, prevFreq);
//             }
//             currBucket->prev->keys.insert(key);
//             keyToBucket[key] = currBucket->prev;
//         }
        
//         // Clean up the bucket it just left
//         currBucket->keys.erase(key);
//         removeBucketIfEmpty(currBucket);
//     }
    
//     string getMaxKey() {
//         if (tail->prev == head) return "";
//         // The bucket right before the dummy tail holds the highest frequency elements
//         return *(tail->prev->keys.begin());
//     }
    
//     string getMinKey() {
//         if (head->next == tail) return "";
//         // The bucket right after the dummy head holds the lowest frequency elements
//         return *(head->next->keys.begin());
//     }
// };



//mine own solution

// class Node{
// public:
// string key;
// int cnt;
// Node* next;
// Node* prev;
//     Node(string key){
//         this->key = key;
//         cnt = 1;
//         next = prev = nullptr;
//     }
// };  

// class AllOne {
// private:
// unordered_map<string,Node*>keyToNode;
// unordered_map<int,pair<Node*,Node*>>freqToDLL;
// int min_freq = INT_MAX;
// int max_freq = INT_MIN;

// void addNode(Node* newNode,int freq){

//     if(freqToDLL.find(freq) == freqToDLL.end()){
//         Node* head = new Node("-1");
//         Node* tail = new  Node("-1");
//         head->next = tail;
//         tail->prev = head;
//         freqToDLL[freq] = {head,tail};
//     }

//     Node* head = freqToDLL[freq].first;
//     Node* nxt = head->next;
//     head->next = newNode;
//     newNode->prev = head;
//     newNode->next = nxt;
//     nxt->prev = newNode;
// }

// void removeNode(Node* nd){
//     Node* prv = nd->prev;
//     prv->next = nd->next;
//     nd->next->prev = prv;
//     nd->prev = nullptr;
//     nd->next = nullptr;
// }

// public:
//     AllOne() {

//     }
    
//     void inc(string key) {
//         if(keyToNode.find(key) == keyToNode.end()){
//             Node* newNode = new Node(key);
//             min_freq = 1;
//             max_freq = max(max_freq,min_freq);
//             keyToNode[key] = newNode;
//             addNode(newNode,min_freq);
//             return;
//         }
//         Node* nd = keyToNode[key];
//         int count = nd->cnt;
//         removeNode(nd);

//         max_freq = max(max_freq,count+1);
//         if(freqToDLL[count].first->next == freqToDLL[count].second){
//                         delete freqToDLL[count].first;
//             delete freqToDLL[count].second;
//             freqToDLL.erase(count);
//             if (min_freq == count) {
//                 min_freq++;
//                 while (min_freq <= max_freq && freqToDLL.find(min_freq) == freqToDLL.end()) {
//                     min_freq++;
//                 }
//             }
//             if (max_freq == count) {
//                 max_freq--;
//                 while (max_freq >= min_freq && freqToDLL.find(max_freq) == freqToDLL.end()) {
//                     max_freq--;
//                 }
//             } 
//         }
//         count++;
//         nd->cnt = count;
//                 max_freq = max(max_freq, count);
//         if (count < min_freq) {
//             min_freq = count;
//         }
//         addNode(nd,count);
//     }
    
//     void dec(string key) {
//          Node* nd = keyToNode[key];
//         int count = nd->cnt;
//         removeNode(nd);
        
//         // Remove tracking of the list if it becomes empty
//         if (freqToDLL[count].first->next == freqToDLL[count].second) {
//             delete freqToDLL[count].first;
//             delete freqToDLL[count].second;
//             freqToDLL.erase(count);
            
//             if (min_freq == count) {
//                 min_freq++;
//                 while (min_freq <= max_freq && freqToDLL.find(min_freq) == freqToDLL.end()) {
//                     min_freq++;
//                 }
//             }
//             if (max_freq == count) {
//                 max_freq--;
//                 while (max_freq >= min_freq && freqToDLL.find(max_freq) == freqToDLL.end()) {
//                     max_freq--;
//                 }
//             }
//         }

//         nd->cnt--;
//         if (nd->cnt == 0) {
//             keyToNode.erase(key);
//             delete nd;
//             if (keyToNode.empty()) {
//                 min_freq = INT_MAX;
//                 max_freq = INT_MIN;
//             }
//             return;
//         }

//         if (nd->cnt < min_freq) {
//             min_freq = nd->cnt;
//         }
//         max_freq = max(max_freq, nd->cnt);
//         addNode(nd, nd->cnt);
//     }
    
//     string getMaxKey() {
//         if(max_freq == 0 || max_freq == INT_MIN){
//             return "";
//         }
//         Node* nd = freqToDLL[max_freq].second->prev;
//         return nd->key;
//     }
    
//     string getMinKey(){
//         if(min_freq == 0 || min_freq == INT_MAX){
//             return "";
//         }
//         Node* nd = freqToDLL[min_freq].second->prev;
//         return nd->key;
//     }
// };

// /**
//  * Your AllOne object will be instantiated and called as such:
//  * AllOne* obj = new AllOne();
//  * obj->inc(key);
//  * obj->dec(key);
//  * string param_3 = obj->getMaxKey();
//  * string param_4 = obj->getMinKey();
//  */