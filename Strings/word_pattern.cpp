//in this question we have given a string of words and a pattern of char , we need to check bijections such that no pattern char matches two different words , or two words matches to same pattern char
//Given a pattern and a string s, find if s follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:
// Each letter in pattern maps to exactly one unique word in s.
// Each unique word in s maps to exactly one letter in pattern.
// No two letters map to the same word, and no two words map to the same letter.

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<set>

// extracting words from our string
    std::vector<std::string> extractwords(std::string& s) {
        std::string temp = "";
        std::vector<std::string> words;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                words.push_back(temp);
                temp = "";
            } else {
                temp += s[i];
            }
        }
        words.push_back(temp);
        return words;
    }

    bool wordPattern(std::string pattern, std::string s) {
        // Map: word -> pattern character
        std::unordered_map<std::string, char> wordTochar;
        // Set to ensure no two words map to same character
        std::set<char> usedchar;
        std::vector<std::string> words = extractwords(s);
        //if number of patterns are not equal to our number of words , then we cant map
        if (pattern.size() != words.size())
            return false;
        for (int i = 0; i < words.size(); i++) {
           std:: string word = words[i];
            char ch = pattern[i];

            if (!wordTochar.count(word)) {
                if (usedchar.find(ch) == usedchar.end()) {
                    wordTochar[word] = ch;
                    usedchar.insert(ch);
                } else {
                    return false;
                }
            } else {
                if (wordTochar[word] != ch) {
                    return false;
                }
            }
        }
        return true;
    }

    int main(){
        std::string s = "dog cat cat fish";
        std::string pattern = "abba";
        if(wordPattern(pattern,s)){
            std::cout<<"successful word bijection to pattern";
        }
        else{
            std::cout<<"failed to map words to pattern char";
        }
        return 0;
    }