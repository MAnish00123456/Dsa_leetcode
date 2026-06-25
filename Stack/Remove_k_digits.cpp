// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
class Solution {
    public:
        std::string removeKdigits(std::string num, int k) {
         std::stack<char>st;
        
        //monotonic increasing stack from left to right to remove k greater digits
         for(char ch : num){
            while(!st.empty() && k > 0 && ch < st.top()){
                st.pop();
                k--;
            }
            st.push(ch);
         }
    //if deletions are still pending  and stack is monotonic increasing , pop out top element
         while(k-- && !st.empty())st.pop();
    
         std::string ans = "";
         while(!st.empty()){
            ans += st.top();
            st.pop();
         }   
         std::reverse(ans.begin(),ans.end());
         //remove leading zeroes
         int i = 0;
         while(i < ans.size() && ans[i] == '0'){
            i++;
         }
         //either the string is empty or have all zeroes , return "0" for it else the substring
         return ans.size() == i?"0":ans.substr(i);
        }
    };
int main(){
    std::string str = "1432219";
    int k = 3;
    Solution sol1;
    std::string ans = sol1.removeKdigits(str,k);
    std::cout<<ans;
    return 0;
}