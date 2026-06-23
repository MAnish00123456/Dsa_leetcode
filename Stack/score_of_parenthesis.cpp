// Given a balanced parentheses string s, return the score of the string.

// The score of a balanced parentheses string is based on the following rule:

// "()" has score 1.
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.

// Input: s = "(())"
// Output: 2

#include<iostream>
#include<stack>
#include<string>

class Solution {
    public:
        int scoreOfParentheses(std::string s) {
            // int score = 0;
            // stack<int>st;
            // st.push(0); // Base score for the current nesting level. The bottom 0
            // represents the score accumulated outside all parentheses. for(char ch
            // : s){
            //     if('(' == ch){
            //         st.push(0); // Start a new nesting level. This 0 will
            //         accumulate the score inside the current '(' ... ')'.
            //     }else{
            //         int val = st.top();
            //         score = max(2 * val , 1);
            //         st.pop();
            //         int val1 = st.top();
            //         st.pop();
            //         st.push(score + val1);
            //     }
            // }
            // return st.top();
            int depth = 0; // Current nesting depth.
            int score = 0;
    
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(') {
                    depth++;
                } else {
                    depth--;
    
                    // Every primitive "()" contributes 1.
                    // If it is nested inside k pairs, its score becomes 2^k.
                    // After decrementing depth, 'depth' equals exactly k.
                    if (s[i - 1] == '(') {
                        score += (1 << depth);
                    }
                }
            }
    
            return score;
        }
    };

    int main(){
        std::string str = "(())(())";
        Solution sol1;
        int score = sol1.scoreOfParentheses(str);
        std::cout<<score;
        return 0;
    }