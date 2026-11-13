// Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

// Implement the MyStack class:

// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.
// Notes:

// You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
// Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

// class MyStack {
//     queue<int>q;
// public:
//     MyStack() {
        
//     }
    
//     void push(int x) {
//         q.push(x);
//         for(int i = 0 ; i < q.size() - 1 ; i++){
//             q.push(q.front());
//             q.pop();
//         }
//     }
    
//     int pop() {
//         int res = q.front();
//         q.pop();
//         return res;
//     }
    
//     int top() {
//         return q.front();
//     }
    
//     bool empty() {
//         return q.size() == 0;
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//  class MyStack {
//     queue<int>readQ;
//     queue<int>tempQ;
// public:
//     MyStack() {
        
//     }
    
//     void push(int x) {
//         readQ.push(x);
//     }
    
//     int pop() {
//         if(readQ.size() == 0)return -1;
        
//         if(readQ.size() != 1){
//        while(readQ.size() != 1){
//         tempQ.push(readQ.front());
//         readQ.pop();
//        }
//         }
// int res = readQ.front();
// readQ.pop();
// while(!tempQ.empty()){
//     readQ.push(tempQ.front());
//     tempQ.pop();
// }

// return res;
//     }
    
//     int top() {
//       if(readQ.size() == 0)return -1;
        
//         if(readQ.size() != 1){
//        while(readQ.size() != 1){
//         tempQ.push(readQ.front());
//         readQ.pop();
//        }
//         }
// int res = readQ.front();
// readQ.pop();
// tempQ.push(res);
// while(!tempQ.empty()){
//     readQ.push(tempQ.front());
//     tempQ.pop();
// }
// return res;
//     }
    
//     bool empty() {
//        return (readQ.size() == 0 && tempQ.size() == 0); 
//     }
// };