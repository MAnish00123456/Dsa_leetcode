// You are given a string password.

// The strength of the password is calculated based on the following rules:

// 1 point for each distinct lowercase letter ('a' to 'z').
// 2 points for each distinct uppercase letter ('A' to 'Z').
// 3 points for each distinct digit ('0' to '9').
// 5 points for each distinct special character from the set "!@#$".
// Each character contributes at most once, even if it appears multiple times.

// Return an integer denoting the strength of the password.

#include<iostream>
#include<string>
#include<set>
class Solution {
    public:
        int passwordStrength(std::string password) {
            std::set<char>Hashset;
            for(char ch : password)Hashset.insert(ch);
                int strength = 0;
            for(char ch :  Hashset){
                if(islower(ch)){
                    strength+=1;
                }else if(isupper(ch)){
                    strength+=2;
                }else if(isdigit(ch)){
                    strength+=3;
                }else{
                    strength+=5;
                }
            }
            return strength;
        }
    };

    int main(){
        std::string str = "aAbB13@!";
        Solution sol1;
        int strength = sol1.passwordStrength(str);
        std::cout<<strength;
        return 0; 
    }