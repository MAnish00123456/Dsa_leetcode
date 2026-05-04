// A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.
// Given a string word, return the number of vowel substrings in word.

#include<iostream>
#include<string>
#include<unordered_map>

bool isVowel(char& ch){
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
}

int countVowelsubstr(std::string str){
    int count = 0 ;
    std::unordered_map<char,int>Map;
    for(int i = 0 ; i < str.length() ; i++){
        Map.clear();
        for(int k = i ; k < str.length() && isVowel(str[k]) ; k++){
            Map[str[k]]++;
            if(Map.size() == 5) count++;
        }
    }
    return count;
}

int main(){
    std::string str = "cuaieuouac";
    int count = countVowelsubstr(str);
    std::cout<<count;
    return 0;
}