// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
// The test cases are generated so that the length of the output will never exceed 105.

// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"

#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
class Solution {
    bool isdigit(char ch){
        if(ch >= '0' && ch <= '9'){
            return true;
        }
        return false;
    }
public:
    std::string decodeString(std::string s) {
        std::stack<char>msg;
        std::stack<int>digit;

        std::string Ans = "";

        for(int i = 0 ; i < s.size() ; i++){
            if(isdigit(s[i])){
                std::string dig = "";
                while(isdigit(s[i])){
                    dig += s[i++];
                } 
            digit.push(stoi(dig));
            i--;
            }else if('[' == s[i]){
                msg.push(s[i]);
            }else if(']' == s[i]){
                std::string msg1 = "";
                while(!msg.empty() && msg.top() != '['){
                    msg1 += msg.top();
                    msg.pop();
                }
                std::reverse(msg1.begin(),msg1.end());
                msg.pop();//remove '[' bracket
                int k = digit.top();
                digit.pop();
                std::string currBlock = "";
                while(k != 0){
                    currBlock += msg1;
                    k--;
                }
                if(!msg.empty()){
                    for(int i = 0 ; i < currBlock.size() ; i++){
                        msg.push(currBlock[i]);
                    } 
                }else{
                    Ans += currBlock;
                }
                currBlock = "";
            }else{
                msg.push(s[i]);
            }
        }
        if(!msg.empty()){
            std::string rem = "";
            while(!msg.empty()){
                rem += msg.top();
                msg.pop();
            }
            reverse(rem.begin(),rem.end());
            Ans += rem;
        }
    return Ans;
    }
};

int main(){
    std::string str = "2[abc]3[cd]ef";
    Solution sol1;
    std::string ans = sol1.decodeString(str);
    std::cout<<ans;
    return 0;
}