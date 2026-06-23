// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".

#include<iostream>
#include<stack>
#include<string>

class Solution {
    public:
        int longestValidParentheses(std::string s) {
            //stack approach is used to store the last valid index
            // int maxLen = 0;
            // stack<int>st;
            // st.push(-1); //for cases where our first char is an closing bracket.stack will always be non empty for every valid length  of parentheses
            // for(int i = 0 ; i < s.size() ; i++){
            //     if('(' == s[i]){
            //         st.push(i);
            //     }else{
            //         st.pop();
            //         if(st.empty()){
            //             st.push(i);//start new length from this index , as before this index length can or cannot be max
            //         }else{
            //             maxLen = max(maxLen , i-st.top());
            //         }
            //     }
            // }
            // return maxLen;
    
            //2nd approach , with no stack
            int maxLen = 0;
            int left = 0;//store count of '(' 
            int right = 0;//store count of ')
    
            //traverse from left to right for cases like '())' where closing brackets > opening brackets
            for(char ch : s){
                if('(' == ch){
                    left++;
                }else{
                    right++;
                }
                if(left == right){
                    maxLen = std::max(maxLen , 2*right);
                }else if(right > left){
                    left = right = 0;
                }
            }
            //now traverse from right to left for cases like '(()' where opening brackets > closing brackets
            left = right = 0;
            for(int i = s.size() - 1 ; i >= 0 ; i--){
                if(s[i] == '('){
                    left++;
                }else{
                    right++;
                }
    
                if(left == right){
                    maxLen = std::max(maxLen , 2 * right);
                }else if(left > right){
                    left = right = 0;
                }
            }
    return maxLen;
        }
    };
int main(){
std::string str = "))()()()(())";
Solution sol1;
int len = sol1.longestValidParentheses(str);
std::cout<<len;
return 0;
}