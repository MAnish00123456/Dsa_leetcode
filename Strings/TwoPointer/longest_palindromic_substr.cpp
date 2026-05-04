#include<iostream>
#include<string>

//same as palindromic substrings logic of expanding outwards from center
// Treat each index (and gap between indices) as a center
// Expand outward to find the longest palindrome
std::string longestPalindrome(std::string str){
  if(str.length() <= 0) return "";
    std::string ans;
    int maxlen = 0;
int len =0;
for(int i = 0 ; i < str.length() ; i++){
    int left = i , right = i;
    while(left >=0 && right < str.length() && str[left] == str[right]){
        len = right - left + 1;
        if(len > maxlen){
            maxlen = len;
            ans = str.substr(left, right-left+1);
        }
        left--;
        right++;
    }
     left = i , right = i+1;
    while(left >=0 && right < str.length() && str[left] == str[right]){
        len = right - left + 1;
        if(len > maxlen){
                        maxlen = len;
            ans = str.substr(left, right-left+1);
        }
        left--;
        right++;
    }

}
return ans;
}

int main(){
    std::string str = "babad";
    std::string ans = longestPalindrome(str);
    std::cout<<"answer : "<<ans;
}