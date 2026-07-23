// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

#include<iostream>
#include<string>
#include<vector>

class Solution {
    bool validoccurence(std::vector<int>&freq){
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }
public:
    int numberOfSubstrings(std::string s) {
        int tot = 0;
        std::vector<int>freq(3,0);
        int r = 0;
        int sz = s.size();
        int l = -1;
        //when we get a valid window at r index , we can say that including current window our all future window substrings will always be valid. so we count of all total windows we can form after r index , where l -- r is valid
        while(r < s.size()){
            freq[s[r]-'a']++;
            while(validoccurence(freq)){
                tot += (sz - r);
                l++;
                freq[s[l]-'a']--;
            }
            r++;
        }
        return tot;
    }
};

int main(){
    Solution sol1;
    std::string s = "abcabc";
    std::cout<<"Count : "<<sol1.numberOfSubstrings(s);
    return 0;
}