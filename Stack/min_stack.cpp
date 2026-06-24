// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int value) pushes the element value onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

#include<iostream>
#include<stack>
#include<climits>


class MinStack {
    int minElem = INT_MAX;
    std::stack<std::pair<int,int>>st;
public:
    MinStack() {
    }
    
    void push(int value) {
        if(st.empty()) {
            st.push({value,value});
        }else{
        minElem = std::min(value,st.top().second);
        st.push({value,minElem});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin(){
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 int main(){
    MinStack* minStack =  new MinStack();
    minStack->push(0);
    minStack->push(5);
    minStack->push(-1);
    minStack->push(-11);

    std::cout<<minStack->top()<<std::endl;
    minStack->pop();
    std::cout<<minStack->getMin();
return 0;
 }