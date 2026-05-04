//given a string s , return the length of longest substring having exactly k distinct characters , if no substring exists like that , return -1;

#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

int maxlen(std::string str , int k){
    int maxlen = -1;
    int l = -1;
    std::unordered_map<char,int>Map;
    for(int i = 0 ; i < str.size() ; i++){
        Map[str[i]]++;
        while(Map.size() > k){
            l++;
            Map[str[l]]--;
            if(0 == Map[str[l]]){
                Map.erase(str[l]);
            }
        }
        if(Map.size() == k){
            maxlen = std::max(maxlen , i-l);
        }
    }
    return maxlen;
}

int longestKSubstr(std::string &str , int k ){
    if(k > str.size()) return -1;
    return maxlen(str,k);
}


int main(){
    std::string str = "aabacbebebe";
    int k = 3;
    int maxlen = longestKSubstr(str,k);
    std::cout<<"longest length : "<<maxlen;
    return 0;
}