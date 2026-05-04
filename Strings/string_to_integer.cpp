#include<iostream>
#include<string>
//given a string of nums , convert it into integer
//leading spaces , signedness , overflow , nondigit chars. all edge cases
class Solution {
    public:
        int myAtoi(std::string s) {
            //if string is empty , return 0
            if(s.empty()) return 0;
            int i = 0;
            bool isstartNeg = false;
            //skip leading spaces
            while(i<s.size() && s[i] == ' ')i++;
    
            //check if first symbol is '-' or '+' , to determine the signedness of Ans
            if (i < s.size() && (s[i] == '-' || s[i]=='+')) {
                if(s[i] == '-'){
                isstartNeg = true;
                }
                i++;
            }
            
            bool leadingzero = true;
            int Ans = 0;
            
            //traverse the string
            while (i < s.size()) {
                //skip leading zeroes
                while (i < s.size() && s[i] == '0' && leadingzero) {
                    i++;
                    leadingzero = true;
                }
    
                leadingzero = false;
                //if current char is non digit or we traversed whole string : return Ans based on signedness
                if (i >= s.size() || (!isdigit(s[i]))) {
                    return isstartNeg?-Ans:Ans;
                }
    
                //fetch current number
                int num = s[i] - '0';
                //overflow condition , if either Ans is greater than INT_MAX or if is equal to it , then check the num to be added is less than 7 or not
                //then return based on signedness
                if (Ans > INT_MAX / 10 ||(Ans == INT_MAX/10 && num > 7)) {
                    return isstartNeg?INT_MIN:INT_MAX;
                }
                //conclude Ans
                Ans = Ans * 10 + num;
                i++;
            }
            //return Ans based on signedness
            if (isstartNeg) {
                Ans = -Ans;
                return Ans;
            }
            return Ans;
        }
    };

int main(){
    Solution sol;
    std::string str="42";
    int ans = sol.myAtoi(str);
    std::cout<<ans;
}