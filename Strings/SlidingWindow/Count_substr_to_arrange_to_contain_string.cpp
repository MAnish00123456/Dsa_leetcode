//in this question we have been given 2 strings word1 , word2 , we need to find total substrings in word1 that can be rearranged to have word2 as its prefix
// for ex word1 = "bcca" and word2 = "abc"
//count would be 1 where word1 = " abcc" is valid substr

//sliding window , concept similar to min_window_substr

#include<iostream>
#include<string>
#include<unordered_map>

#define ll long long 

ll validSubstringCount(std::string& word1, std::string& word2){
    
    // If word2 is longer, impossible to form a valid substring
    if (word2.length() > word1.length())
        return 0;
   std::unordered_map<char, int> Map2;

    // Store required frequency of each character from word2
    for (char ch : word2)
        Map2[ch]++;
    // Number of unique characters whose required frequency is still not
    // satisfied
    int uniquecharcount = Map2.size();

    ll winSt = 0, winEnd = 0;
    ll count = 0;
    while (winEnd < word1.size()) {

        // extend
        // Include current character into window
        char ch = word1[winEnd];
        if (Map2.count(ch)) {
            Map2[ch]--;
            if (0 == Map2[ch]) {
                uniquecharcount--;
            }
        }

        // shrinking
        // If all required characters are present, current window is valid
        while (0 == uniquecharcount) {
            // All substrings starting from winSt and ending from winEnd to
            // n-1 will remain valid, so count all of them at once
            count += (word1.size() - winEnd);
            // Remove leftmost character and try to shrink the window
            ch = word1[winSt];
            // If requirement becomes unmet again, window becomes invalid
            if (Map2.count(ch)) {
                Map2[ch]++;
                if (0 < Map2[ch]) {
                    uniquecharcount++;
                }
            }
            winSt++;
        }
        winEnd++;
    }

    return count;

}

int main(){
    std::string word1 = "abcabc";
    std::string word2 = "abc";
    ll count = validSubstringCount(word1,word2);
    std::cout<<"count of substrings that can be rearranged in word1 to have word2 as prefix : "<<count;
    return 0;
}