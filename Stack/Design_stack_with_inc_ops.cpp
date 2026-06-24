// Design a stack that supports increment operations on its elements.

// Implement the CustomStack class:

// CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
// void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
// int pop() Pops and returns the top of the stack or -1 if the stack is empty.
// void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.

// Input
// ["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
// [[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
// Output
// [null,null,null,2,null,null,null,null,null,103,202,201,-1]

#include<iostream>
#include<stack>

class CustomStack {
    int limit = 0;
    std::stack<int>orig;
    std::stack<int>modif;
public:
    CustomStack(int maxSize) {
        limit = maxSize;
    }
    
    void push(int x) {
        if(orig.size() < limit){
            orig.push(x);
        }
    }
    
    int pop() {
        if(orig.empty())return -1;
        int val = orig.top();
        orig.pop();
        return val;
    }
    
    void increment(int k, int val) {
        while(!orig.empty() && orig.size() > k){
            modif.push(orig.top());
            orig.pop();
        }
        while(!orig.empty()){
            modif.push(orig.top() + val);
            orig.pop();
        }

        while(!modif.empty()){
            orig.push(modif.top());
            modif.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */