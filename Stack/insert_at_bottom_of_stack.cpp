// You are given a stack st of n integers and an element x. You have to insert x at the bottom of the given stack. 

// Input:
// n = 5
// x = 2
// st = {4,3,2,1,8}
// Output:
// {2,4,3,2,1,8}

#include<iostream>
#include<stack>


class Solution {
    public:
      std::stack<int> insertAtBottom(std::stack<int>& st, int x) {
          
          auto insertVal = [&](auto&& self) -> void {
              if(!st.empty()){
                  int curr = st.top();
                  st.pop();
                  self(self);
                  st.push(curr);
              }
              else{st.push(x);}
          };
          
          insertVal(insertVal);
          return st;
      }
  };

  int  main(){
    std::stack<int> st; 
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(8);
    int x = 9;
    Solution sol1;
    sol1.insertAtBottom(st,x);
    while(!st.empty()){
        std::cout<<st.top()<<" ";
        st.pop();
    }
    return 0;

  }



  /*
Generic Recursive Lambda

Normally, a lambda cannot call itself because it doesn't exist while
it is being initialized.

To enable recursion, we pass the lambda itself as a parameter.

auto&& self
-------------
- 'self' is just a parameter name (can be recur, dfs, me, etc.).
- 'auto&&' is a forwarding/universal reference that binds to the
  lambda object without copying it.
- It lets the compiler deduce the unnamed lambda type automatically.

Why self(self)?
---------------
The first 'self' = function to call.
The second 'self' = argument passed to the recursive call.

Initial call:
    insertVal(insertVal);

Inside recursion:
    self(self);

This is equivalent to repeatedly calling:

    insertVal(insertVal);

Mental Model:
-------------
Think of it as passing the function to itself.

Instead of:
    dfs(node);

We write:
    dfs(dfs, node);

where the first dfs is "call this function",
and the second dfs is "pass yourself so recursion can continue".

Use this whenever:
------------------
- Helper function is used only locally.
- Need recursive lambda without std::function.
- Avoid creating a separate member/helper function.
*/