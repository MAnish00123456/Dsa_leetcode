// Given a stack s, delete the middle element of the stack without using any additional data structure.

// Input: s = [10, 20, 30, 40, 50]
// Output: [50, 40, 20, 10]
// Explanation: The bottom-most element will be 10 and the top-most element will be 50. Middle element will be element at index 3 from bottom, which is 30. Deleting 30, stack will look like {10 20 40 50}.

#include<iostream>
#include<stack>

class Solution {
    public:
      // Function to delete middle element of a stack.
      void deleteMid(std::stack<int>& s) {
          int sz = s.size() + 1;
          int mid = sz/2;
          int cnt = 0;
          bool isodd = (s.size() % 2 != 0 ? true:false);
          if(!isodd){
              mid +=1;
          }
          auto deleteM = [&](auto&& self)->void{
              
              cnt += 1;
              if(cnt != mid){
              int curr = s.top();
              s.pop();
              self(self);
              s.push(curr);
              }else{
                  s.pop();
                  return;
              }
          };
          deleteM(deleteM);
          return ;
      }
  };


  int main(){
    std::stack<int> st; 
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(8);
    Solution sol1;
    sol1.deleteMid(st);
    while(!st.empty()){
        std::cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
  }