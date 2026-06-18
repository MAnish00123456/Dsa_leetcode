// You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
// We repeatedly make k duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

// Input: s = "deeedbbcccbdaa", k = 3
// Output: "aa"
// Explanation: 
// First delete "eee" and "ccc", get "ddbbbdaa"
// Then delete "bbb", get "dddaa"
// Finally delete "ddd", get "aa"

#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

class Solution {
    public:
        std::string removeDuplicates(std::string s, int k) {
            std::stack<std::pair<char,int>>st;
    
            for(int i = 0 ; i < s.size() ; i++){
                if(!st.empty() && st.top().first == s[i]){
                    st.top().second += 1;
                    if(st.top().second == k){
                        st.pop();
                    }    
                }
                else {st.push({s[i],1});}
            }
    
            std::string Ans = "";
            while(!st.empty()){
                Ans.append(st.top().second , st.top().first);
                st.pop();
            }
            reverse(Ans.begin(),Ans.end());
            return Ans;
        }
    };

int  main(){
    std::string str = "deeedbbcccbdaa";
    int k = 3;
    Solution sol1;
    std::string Ans = sol1.removeDuplicates(str,k);
    std::cout<<Ans;
    return 0;
}