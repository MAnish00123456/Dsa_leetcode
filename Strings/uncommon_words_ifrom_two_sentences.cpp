// A sentence is a string of single-space separated words where each word consists only of lowercase letters.
// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
// Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) {

    std::unordered_map<std::string, int> Map1;
    for (int i = 0; i < s1.length(); i++) {
        std::string word = "";
        while (i < s1.length() && s1[i] != ' ') {
            word += s1[i];
            i++;
        }
        if (!word.empty()) {
            Map1[word]++;
        } else {
            i++;
        }
    }

    for (int i = 0; i < s2.length(); i++) {
        std::string wordd = "";
        while (i < s2.length() && s2[i] != ' ') {
            wordd += s2[i];
            i++;
        }
        if (!wordd.empty()) {
            Map1[wordd]++;
        } else {
            i++;
        }
    }

    std::vector<std::string> ans;
    for (auto const& [key, value] : Map1) {
        if (value == 1) {
            ans.push_back(key);
        }
    }
    return ans;
}

int main(){
    std::string s1 = "this apple is sweet";
    std::string s2 = "this apple is sour";
    std::vector<std::string> ans = uncommonFromSentences(s1,s2);
    for(std::string str : ans){
        std::cout<<str<<"  ";
    }
    return 0;
}