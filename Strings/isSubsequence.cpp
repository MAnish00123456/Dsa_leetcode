// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. 
// (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

#include<iostream>
#include<string>
class Solution {
    public:
        bool isSubsequence(std::string s, std::string t) {
         int idx1 = 0 , idx2 = 0;
         while(idx1 < s.length() && idx2 <t.length() ){
            if(s[idx1] == t[idx2]){
                idx1++;
            }
            idx2++;
         }   
         return idx1 == s.length();
        }
    };

    int main(){
        std::string s = "abc";
        std::string t = "ahbgdc";
        Solution sol1;
        if(sol1.isSubsequence(s,t)){
            std::cout<<"s is a subsequence of t"<<std::endl;
        }
        else{
            std::cout<<"s is not a subsequence of t"<<std::endl;
        }
return 0;
    }