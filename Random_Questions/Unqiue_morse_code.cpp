// International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

// 'a' maps to ".-",
// 'b' maps to "-...",
// 'c' maps to "-.-.", and so on.
// For convenience, the full table for the 26 letters of the English alphabet is given below:

// [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
// Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.

// For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.
// Return the number of different transformations among all words we have.

#include<iostream>
#include<vector>
#include<string>
#include<set>
class Solution {
    public:
        int uniqueMorseRepresentations(std::vector<std::string>& words) {
           std:: set<std::string>Unique;
            std::vector<std::string> MorseCode ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
            for(int i = 0 ; i < words.size() ; i++){
                std::string code ="";
                for(char ch : words[i]){
                    code+=MorseCode[ch-'a'];
                }
                Unique.insert(code);
            }
            return Unique.size();
        }
    };

int main(){
    std::vector<std::string> words = {"gin","zen","gig","msg"};
    Solution sol1;
    int count = sol1.uniqueMorseRepresentations(words);
    std::cout<<count;
    return 0;
}