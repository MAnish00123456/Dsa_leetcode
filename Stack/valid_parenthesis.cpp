// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

#include<iostream>
#include<string>
#include<stack>

class Solution {
    public:
        bool isValid(std::string s) {
            if (s.size() < 2)
                return false;
            std::stack<char> st;
            for (char ch : s) {
                if (ch == '(' || ch == '[' || ch == '{') {
                    st.push(ch);
                }
                 else {
                if(st.empty())
                    {return false;}
               if((ch == ')' && st.top() == '(') ||
                     (ch == ']' && st.top() == '[') ||
                     (ch == '}' && st.top() == '{')){
                st.pop();
                    }else{
                        return false;
                    }
                 }
    
            }
            return st.empty();
        }
    };

    int main(){
        std::string str = "{{)}}";
        Solution sol1;
        if(sol1.isValid(str)){
            std::cout<<"Valid";
        }else{
            std::cout<<"Invalid";
        }
        return 0;
    }