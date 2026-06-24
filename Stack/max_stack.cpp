// Implement a class SpecialStack that supports following operations:

// push(x) – Insert an integer x onto the stack.
// pop() – Remove the top element from the stack.
// peek() – Return the top element from the stack. If the stack is empty, return -1.
// getMax() – Retrieve the maximum element from the stack in O(1) time. If the stack is empty, return -1.
// isEmpty() –  Return true if stack is empty, else false
// There will be a sequence of queries queries[][]. The queries are represented in numeric form:

// 1 x : Call push(x)
// 2:  Call pop()
// 3: Call peek()
// 4: Call getMax()
// 5: Call isEmpty()

// Input: q = 7, queries[][] = [[1, 2], [1, 3], [3], [2], [4], [1, 1], [4]]
// Output: [3, 2, 2]
// Explanation: Queries on stack are as follows:
// push(2) into the Stack
// push(3) into the Stack
// return top of the stack, i.e 3
// remove the element 3 from the top of the stack
// return maximum element from the stack i.e 2
// push(1) into the stack
// return maximum element from the stack i.e 2

#include<iostream>
#include<stack>
#include<climits>

class SpecialStack {
    std::stack<std::pair<int,int>>st;
    int maxval = -1;
  public:
    SpecialStack() {
        // Define Stack
    }

    void push(int x) {
        // Push an element into the stack
        if(st.empty()){
            st.push({x,x});
        }else{
            maxval = std::max(x,st.top().second);
            st.push({x,maxval});
        }
    }

    void pop() {
        // Remove the top element from the Stack
        if(!st.empty())st.pop();
    }

    int peek() {
        // Returns the top element
        if(!st.empty())return st.top().first;
        return -1;
    }

    bool isEmpty() {
        // Check if stack is empty
    return st.empty();
    }

    int getMax() {
        // Return maximum element of Stack
                if(!st.empty())return st.top().second;
        return -1;
    }
};

int main(){
    SpecialStack* st = new SpecialStack();
    st->push(-10);
    st->push(-1);
    st->push(10);
    st->push(1);

    std::cout<<st->getMax()<<std::endl;
    st->pop();
    std::cout<<st->peek();
    return 0;
}