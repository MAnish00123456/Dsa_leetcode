// You are given a string s, which contains stars *.
// In one operation, you can:

// Choose a star in s.
// Remove the closest non-star character to its left, as well as remove the star itself.
// Return the string after all stars have been removed.

// Note:
// The input will be generated such that the operation is always possible.
// It can be shown that the resulting string will always be unique.

// Input: s = "leet**cod*e"
// Output: "lecoe"

#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

class Solution {
    public:
        std::string removeStars(std::string s) {
            std::stack<char>st;
            std::string Ans = "";
            for(char ch : s){
                if(ch == '*'){
                    if(!st.empty()){
                        st.pop();
                    }
                }else{
                    st.push(ch);
                }
            }
    
            while(!st.empty()){
                Ans += st.top();
                st.pop();
            }
            reverse(Ans.begin(),Ans.end());
            return Ans;
        }
    };

int main(){
    std::string str = "leet**cod*e";
    Solution sol1;
    std::string Ans = sol1.removeStars(str);
    std::cout<<Ans;
    return 0;
}