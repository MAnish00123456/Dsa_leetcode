// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

// Implement the MyQueue class:

// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.
// Notes:

// You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

// Input
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 1, 1, false]

#include<iostream>
#include<stack>

//use of 2 stacks to implement read and write opertaion

class MyQueue {
    std::stack<int> writeStack; // incoming writes
    std::stack<int> readStack;  // outgoing reads   
public:
   MyQueue() {
   }
   
   void push(int x) {
       writeStack.push(x);
   }
   
   int pop() {
    if(readStack.empty()){
       while(!writeStack.empty()){
           readStack.push(writeStack.top());
           writeStack.pop();
       }
    }
    int val = readStack.top();
    readStack.pop();
    return val;
   }
   
   int peek() {
            if(readStack.empty()){
       while(!writeStack.empty()){
           readStack.push(writeStack.top());
           writeStack.pop();
       }
    }
    return readStack.top();
   }
   
   bool empty() {
        if(!writeStack.empty() || !readStack.empty()){
           return false;
        }
        return true;
   }
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/

int main(){
    MyQueue* myQueue = new MyQueue();
    myQueue->push(1);
    myQueue->push(2);
    myQueue->push(3);
    myQueue->push(4);

    int val = myQueue->pop();;
    int val1 = myQueue->peek();

    std::cout<<val<<" "<<val1<<std::endl;
    return 0;
}