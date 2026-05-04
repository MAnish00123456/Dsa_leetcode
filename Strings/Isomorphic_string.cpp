//similar problem as word_pattern

// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

#include<iostream>
#include<string>
#include<set>
#include<unordered_map>


 

bool isIsomorphic(std::string s, std::string t) {
   std:: unordered_map<char,char>sMap;
    std::set<char>tSet;
    if(s.size() != t.size()) return false;
    for(int i = 0 ; i < s.size() ; i++){
        char sCh = s[i];
        char tCh = t[i];
        if(!sMap.count(sCh)){
            if(tSet.find(tCh) == tSet.end()){
                sMap[sCh] = tCh;
                tSet.insert(tCh);
            }
            else{
                return false;
            }
        }
        else{
            if(sMap[sCh] != tCh){
                return false;
            }
        }
    }
    return true;
}

int main(){
    std::string s = "egg";
    std::string t = "add";
    if(isIsomorphic(s,t)){
        std::cout<<"we can replace charcters of s with t to make them isomorphic";
    }
    else{
        std::cout<<"not isomorphic";
    }
    return 0;
}