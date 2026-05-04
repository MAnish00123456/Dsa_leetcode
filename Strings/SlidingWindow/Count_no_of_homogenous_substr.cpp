// Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.
// A string is homogenous if all the characters of the string are the same.

#include<iostream>
#include<unordered_map>
#include<string>
#define ll long long
const ll  mod = 1e9+7;
//use of hashmap
int countHomogenous(std::string &str){
int l = -1;
std::unordered_map<char,int>Map;
ll count = 0;
for(int i = 0 ; i < str.length() ; i++){
    Map[str[i]]++;
    while(Map.size() > 1){
        l++;
        Map[str[l]]--;
        if(0 == Map[str[l]] ){
            Map.erase(str[l]);
        }
    }
    count += (i-l);
    count = count % mod;
}
return count;
}

//2nd solution without using hashmap
int AcountHomogenous(std::string & str){
    int curr = 0 ; 
    ll count = 0;
    for(int i = 0 ; i < str.length() ; i++){
        if(i > 0 && str[i] == str[i-1]){
            curr++;
        }
        else{
            curr = 1;
        }
        count = (count + curr) % mod;
    }
    return count;
}








int main(){
    std::string str = "abbcccaa";
    int count = AcountHomogenous(str);
    std::cout<<"Count of homogenous substr : "<<count;
    return 0;
}