// Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

// The words in paragraph are case-insensitive and the answer should be returned in lowercase.

// Note that words can not contain punctuation symbols.

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<climits>

class Solution {
    bool isValid(char ch) {
        if (tolower(ch) >= 'a' && tolower(ch) <= 'z')
            return true;
        return false;
    }
    bool isBanned(std::string word, std::vector<std::string>& banned) {
        for (std::string str : banned) {
            if (word == str)
                return true;
        }
        return false;
    }

public:
    std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned) {
        std::unordered_map<std::string, int> Map;
        for (int i = 0; i < paragraph.size(); i++) {
            while (paragraph[i] == ' ')
                i++;

            std::string word = "";
            while (isValid(paragraph[i])) {
                word += tolower(paragraph[i]);
                i++;
            }
            if (!isBanned(word, banned))
                Map[word]++;
        }
       std:: string common = "";
        int max = INT_MIN;
        for (const auto& pair : Map) {
            if (pair.second > max) {
                common = pair.first;
                max = pair.second;
            }
        }
        return common;
    }
};
int main(){
    Solution sol1;
    std::string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    std::vector<std::string>banned = {"hit"};
    std::string common = sol1.mostCommonWord(paragraph,banned);
    std::cout<<common;
    return 0;
}