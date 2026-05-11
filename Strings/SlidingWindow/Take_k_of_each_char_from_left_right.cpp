// You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.

// Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

// we can rephrase it as , find a window of a max size which we can safely remove from s and still have atleast k freq of each char

//our basic idea to solve to this problem would be that , we will try to find a maximum length of window which we can safely remove from string to maintain atleast k freq of 'a' 'b' 'c' outside the window
//at any point if including one char in window makes us having less than k freq of that char , we will shrink our window till we maintain atleast k freq of chars outside the window

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
class Solution {
    public:
        int takeCharacters(std::string s, int k) {
            std::vector<int> CountChar(3, 0);
            for (char ch : s)
                CountChar[ch - 'a']++;
    //early exit , when we dont have atleast k freq of chars in string
            for (int val : CountChar) {
                if (val < k)
                    return -1;
            }
    
            std::vector<int> WindowFreq(3,0);
            int l = -1;
            int MaxLen = INT_MIN;
            for (int right = 0; right < s.size(); right++) {
                WindowFreq[s[right] - 'a']++; // expand
                //shrinking phase
                while (!(CountChar[0] - WindowFreq[0] >= k) ||
                       !(CountChar[1] - WindowFreq[1] >= k) ||
                       !(CountChar[2] - WindowFreq[2] >= k)) {
                    l++;
                    WindowFreq[s[l] - 'a']--;
                }
                MaxLen = std::max(MaxLen, right - l);
            }
            int minMinutes = s.size() - MaxLen;
            return minMinutes;
        }
    };

    int main(){
        std::string s = "aabaaaacaabc";
        int k = 2;
        Solution sol1;
        int minMinutes = sol1.takeCharacters(s,k);
        std::cout<<minMinutes;
        return 0; 
    }