// A sentence is a list of tokens separated by a single space with no leading or trailing spaces. Every token is either a positive number consisting of digits 0-9
//  with no leading zeros, or a word consisting of lowercase English letters.

// For example, "a puppy has 2 eyes 4 legs" is a sentence with seven tokens: "2" and "4" are numbers and the other tokens such as "puppy" are words.
// Given a string s representing a sentence, you need to check if all the numbers in s are strictly increasing from left to right (i.e., other than the last number, 
//     each number is strictly smaller than the number on its right in s).

// Return true if so, or false otherwise.
#include<iostream>
#include<string>
#include<sstream>


class Solution {
    public:
        bool areNumbersAscending(std::string s) {
            if (s.empty())
                return false;
            int curr = 0; // current number found in string
            int prev = 0; // previous number to compare with
            int num;
            // Use stringstream to split string by spaces
            std::stringstream ss(s);
            std::string word = "";
            // Extract each token (word/number) from string
            while (ss >> word) {
                // Try to convert token into integer
                // If conversion succeeds → this token is a number
                std::stringstream converter(word);
                if (converter >> num) {
                    curr = num;
                    if (curr > prev) {
                        prev = curr;
                    } else {
                        return false;
                    }
                }
            }
            return true;
        }
    };
    
    int main(){
        Solution sol;
        std::string s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles";
        if(sol.areNumbersAscending(s)){
            std::cout<<"Nums are in ascending order in string";
        }
        else{
            std::cout<<"Nums are not in ascending order in string";
        }
return 0;
    }