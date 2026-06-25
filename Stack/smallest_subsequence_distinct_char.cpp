// Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

// Input: s = "bcabc"
// Output: "abc"

#include<iostream>
#include<string>
#include<vector>

#include<iostream>
#include<vector>
#include<string>

class Solution {
    public:
        std::string smallestSubsequence(std::string s) {
            std::vector<int>freqCount(26,0);
            std::vector<bool>visited(26,false);
    
            for(char ch : s)freqCount[ch-'a']++;
    
            std::string st;
    
            for(char ch : s){
                if(visited[ch-'a']){
                    freqCount[ch-'a']--;
                    continue;
                }
                while(!st.empty() && ch < st.back() && freqCount[st.back()-'a'] > 1){
                    freqCount[st.back()-'a']--;
                    visited[st.back()-'a'] = false;
                    st.pop_back();
                }
    
                visited[ch-'a'] = true;
                st.push_back(ch);
            }
            return st;
        }
    };

    int main(){
        std::string str = "bcabc";
        Solution sol1;
        std::string ans = sol1.smallestSubsequence(str);
        std::cout<<ans;
        return 0;
    }