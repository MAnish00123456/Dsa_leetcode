// In this question we have been given a string and we need to return the count of substrings which are palindrome , 
//for ex -> str = "aaab" , palindromic substrings -> "a" "a" "a" "aa" "aa" "aaa" "b" , count = 7

#include<iostream>
#include<string>
#include<vector>

//expand from middle , means at every index , assume it as center and expand from left and right for odd length substrings and check if they are palindrome
//for even length substrings , take current index as left and right = current + 1 and expand outwards checking palindrome
//this makes TC = O(n*n)
int countSubstrings(std::string str){
    if(str.length()<= 0 )return 0;
int count = 0;
for(int i = 0 ; i < str.length() ; i++){
    //for odd length palindromic substring
    int left = i , right = i;
    while(left >= 0 && right < str.length() && str[left] == str[right]){
        count++;
        left--;
        right++;
    }
    // for even length palindromic substring
     left = i , right = i+1;
    while(left >= 0 && right < str.length() && str[left] == str[right]){
        count++;
        left--;
        right++;
    }
}
return count;
}


int main(){
std::string str = "";
int count = countSubstrings(str);
std::cout<<"count of palindromic substrings : "<<count;
return 0;

}