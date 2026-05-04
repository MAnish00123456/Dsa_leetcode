//given a string of roman nums , find the value associated to it , for ex :-> "MCMXCIV" = 1994

#include<iostream>
#include<map>
#include<string>


int romanToInt(std::string s) {
    std::map<char, int> romanMap = {{'I', 1},   {'V', 5},   {'X', 10},
                               {'L', 50},  {'C', 100}, {'D', 500},
                               {'M', 1000}};
    int val = 0;
    for(int i = 0 ; i < s.length()-1 ; i++){
        if(romanMap[s[i]] < romanMap[s[i+1]]){
            val-=romanMap[s[i]];
        }
        else{
            val+=romanMap[s[i]];
        }
    }
    val+=romanMap[s[s.length()-1]];
    return val;
}

int main(){
    std::string str = "MMMDCCXLIX";
    int val = romanToInt(str);
    std::cout<<str<<" :- "<<val;
    return 0;
}