// Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

// Lexicographically Smaller
// A string a is lexicographically smaller than a string b if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b.
// If the first min(a.length, b.length) characters do not differ, then the shorter string is the lexicographically smaller one.
 

// Input: s = "cbacdcbc"
// Output: "acdb"

// : This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

#include<iostream>
#include<vector>
#include<string>

// String (used as a stack):
// Maintains the lexicographically smallest valid answer.

// freqCount:
// Stores the remaining occurrences of each character to determine
// whether it's safe to remove a character from the stack.

// visited:
// Ensures each character appears only once in the answer.
class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::vector<int>freqCount(27,0);
        std::vector<bool>visited(27,false);
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
            st.push_back(ch);
            visited[ch-'a'] = true;
        }


        return st;
    }
};

int main(){
    std::string str = "cbacdcbc";
    Solution sol1;
    std::string ans = sol1.removeDuplicateLetters(str);
    std::cout<<ans;
    return 0;
}