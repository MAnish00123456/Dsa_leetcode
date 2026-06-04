// Given an integer num, return a string of its base 7 representation.

// Input: num = 100
// Output: "202"


//similar algorithm for whatever base we have been given
#include<iostream>
#include<string>
#include<algorithm>

class Solution {
    public:
        std::string convertToBase7(int num) {
            if(num == 0)return "0";
            std::string Num;
            bool isneg = num < 0;
            if(isneg) num = -num;
            while(num){
                Num+= std::to_string(num%7);
                num/=7;
            }
            reverse(Num.begin(),Num.end());
            if(isneg) Num.insert(Num.begin(), '-');
            return Num;
        }
    };

    int main(){
        int num = 100;
        Solution sol1;
        std::string Num = sol1.convertToBase7(num);
        std::cout<<Num;
        return 0;
    }