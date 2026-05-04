//in this question we have been given an array of strings , and we have to find the longest common prefix present in all strings , and if we dont have any in common , we return an empty string
//so what we will do is we will take our first string as reference and then using that string characters , we will traverse over other strings , and everytime we will check if the character is present
//in all other strings in same place , if yes we will add that char to our answer string
//our outer loop will traverse over the first string of the array , and in inner loop we will check char by char for common prefix
//for ex :- strs ={flower,flight,floss} , longest common prefix is fl
//used flower for reference and traverse array by comparing char by char

#include<iostream>
#include<string>
#include<vector>



std::string longestCommonPrefix(std::vector<std::string>&strs){
    if(strs.empty()) return "";
    std::string ans = "";
    std::string first = strs[0];//used for reference
    for(int i = 0 ; i < first.size(); i++){
        for(std::string str : strs ){
            //if our current string current char doesnt match our reference string current char , means no more prefix matched
            if(i >= str.size() || str[i] != first[i]){
                return ans;
            }
        }
        ans+=first[i];
    } 
    return ans;
}



int main(){
std::vector<std::string> strs = {"flower","flock" ,"floss"};
std::string ans = longestCommonPrefix(strs);
std::cout<<"the longest common prefix is : "<<ans;
return 0;
}