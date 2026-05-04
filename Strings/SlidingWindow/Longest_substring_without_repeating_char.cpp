// Given a string s, find the length of the longest substring without duplicate characters.
//s consists of English letters, digits, symbols and spaces.

//use of variable length sliding window + hashmap to silve

#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>


int lengthOfLongestSubstring(std::string s) {
    if(s.size() == 0){
        return 0;
    }
    std::unordered_map<char,int>M;
int maxLen = 0;
int l = -1;
    for(int i = 0 ; i<s.size() ; i++){
        M[s[i]]++;
        while(M[s[i]] != 1){
            l++;
            M[s[l]]--;
        }
maxLen = std::max(maxLen , (i-l));
    }
    return maxLen;
}

int main(){
    // std::string s= "abcabcbb";
    std::string s= "bbbb";
    int maxLen = lengthOfLongestSubstring(s);
    std::cout<<"Length of longest substring without repeating character : "<<maxLen<<std::endl;
    return 0;
}