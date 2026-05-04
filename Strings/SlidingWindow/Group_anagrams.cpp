//in this question we hav been Given an array of strings strs, group the anagrams together. 
//for ex :->
//Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<array>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>&strs){
    // Map each frequency pattern to all strings having that same pattern
    // Anagrams will always share identical character frequencies
std::map<std::array<int,26>,std::vector<std::string>>Map;

for(std::string str :strs){
    // Frequency array to represent current string
    // Example: "abb" -> [1,2,0,0,...]
    std::array<int,26>count = {0};
    for(char ch : str){
        count[ch-'a']++;
    }
    // Group strings with same frequency pattern together
    Map[count].push_back(str);
}

std::vector<std::vector<std::string>>Ans;

    // Extract grouped anagrams from the map
for(auto const& [key,value] : Map){
    Ans.push_back(value);
}
return Ans;
}


int main(){
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> Ans = groupAnagrams(strs);
    for(auto str : Ans){
        for(std::string val:str){
            std::cout<<val<<"  ";
        }
        std::cout<<"\n";
    }
return 0;
}

