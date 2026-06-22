// You are given a 0-indexed string s and a 0-indexed integer array spaces that describes the indices in the original string where spaces will be added. Each space should be inserted before the character at the given index.

// For example, given s = "EnjoyYourCoffee" and spaces = [5, 9], we place spaces before 'Y' and 'C', which are at indices 5 and 9 respectively. Thus, we obtain "Enjoy Your Coffee".
// Return the modified string after the spaces have been added.

// Input: s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
// Output: "Leetcode Helps Me Learn"
// Explanation: 
// The indices 8, 13, and 15 correspond to the underlined characters in "LeetcodeHelpsMeLearn".
// We then place spaces before those characters.

#include<iostream>
#include<string>
#include<vector>

class Solution {
    public:
        std::string addSpaces(std::string s, std::vector<int>& spaces) {
            // vector<string> parts;
            // int Blocklen = 0;
            // int j = 0;
            // string subs = "";
            // string rem = "";
            // for (int i = 0; i < s.size(); i++) {
            //     if (j < spaces.size()) {
            //         int spaceCount = spaces[j++];
            //         while (i < s.size() && Blocklen != spaceCount) {
            //             subs += s[i];
            //             Blocklen++;
            //             i++;
            //         }
            //         i--;
            //         parts.push_back(subs);
            //         subs = "";
            //     } else {
            //         rem += s[i];
            //         if(i == s.size() - 1){
            //             parts.push_back(rem);
            //         }
            //     }
            // }
            // string final = "";
            // for(int i = 0 ; i < parts.size() ; i++){
            //     final += parts[i];
            //     final += " ";
            // }
            // final.pop_back();
            // return final;
             std::string final = "";
            int j = 0;
            for(int i = 0 ; i < s.size() ; i++){
                if(j < spaces.size() && i == spaces[j]){
                    final += ' ';
                    j++;
                }
                final += s[i];
            }
            return final;
        }
    };

int main(){
    std::string str = "LeetcodeHelpsMeLearn";
    std::vector<int>spaces = {8,13,15};
    Solution sol1;
    std::string ans = sol1.addSpaces(str,spaces);
    std::cout<<ans;
    return 0;
}
