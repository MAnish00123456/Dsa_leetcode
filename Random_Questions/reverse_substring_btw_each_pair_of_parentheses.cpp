// You are given a string s that consists of lower case English letters and brackets.

// Reverse the strings in each pair of matching parentheses, starting from the innermost one.

// Your result should not contain any brackets.

// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.


#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
    public:
        string reverseParentheses(string s) {
            stack<int>st;
    
            for(int i = 0 ; i < (int)s.size() ; i++){
                if(s[i] == '('){
                    st.push(i);
                }
                else if(s[i] == ')'){
                    int left = st.top()+1;
                    st.pop();
                    int right = i-1;
                    while(left < s.size() && right >= 0 && left <= right){
                        swap(s[left++],s[right--]);
                    }
                }
            }
    
            string ans;
    
            for(char c : s){
                if(c != '(' && c != ')'){
                    ans += c;
                }
            }
    
            return ans;
    
        }
    };

int main(){
    Solution sol1;

    string s = "(ed(et(oc))el)";
    cout<<sol1.reverseParentheses(s);
    return 0;
}