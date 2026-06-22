// A parentheses string is valid if and only if:

// It is the empty string,
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

// For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
// Return the minimum number of moves required to make s valid.

// Input: s = "((("
// Output: 3

#include<iostream>
#include<string>
#include<stack>

class Solution {
    public:
        int minAddToMakeValid(std::string s) {
            int count = 0;
            std::stack<char> st;
            for (char ch : s) {
                if ('(' == ch || '[' == ch || '{' == ch) {
                    st.push(ch);
                } else {
                    if (st.empty()) {
                        count++;
                    } else if ((')' == ch && '(' == st.top()) ||
                               (']' == ch && '[' == st.top()) ||
                               ('}' == ch && '{' == st.top())) {
                        st.pop();
                    } else {
                        count++;
                    }
                }
            }
            if (!st.empty()) {
                count += st.size();
            }
            return count;
        }
    };
    int main(){
        std::string str = "((())";
        Solution sol1;
        int val = sol1.minAddToMakeValid(str);
        std::cout<<val;
        return 0;
    }