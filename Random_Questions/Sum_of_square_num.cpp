// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 #include<iostream>
 #include<math.h>
class Solution {
    public:
    #define ll long long
        bool judgeSquareSum(int c) {
            ll left = 0 , right = sqrt(c);
            while(left <= right){
                ll val = left*left + right*right;
                if(val == c){
                    return true;
                }
                else if(val > c){
                    right--;
                }
                else{
                    left++;
                }
            }
            return false;
        }
    };
    int main(){
        Solution sol1;
        int c = 5;
        if(sol1.judgeSquareSum(c)){
            std::cout<<"given question condition is satisfied";
        }
        else{
            std::cout<<"given question condition is not satisfied";
        }
        return 0;
    }