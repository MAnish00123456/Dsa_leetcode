// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

// Return the quotient after dividing dividend by divisor.

// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less 
// than -231, then return -231.

// Input: dividend = 10, divisor = 3
// Output: 3
// Explanation: 10/3 = 3.33333.. which is truncated to 3.

#include<iostream>
using namespace std;
class Solution {
    public:
        int divide(int dividend, int divisor) {
            //use bitwise left shifting , and subtract bigger chunks of divisor from dividend until dividend < divisor
            
            //overflow cases
            if(dividend == INT_MIN && divisor== -1)return INT_MAX;
            if(dividend == INT_MIN && divisor == 1)return INT_MIN;
    
            bool sign = (dividend < 0) ^ (divisor < 0);//check if its negative or not , true if any of it is negative
    
            //make both positive if anyone is negative
            long long absDividend = abs((long long)dividend);
            long long absDivisor = abs((long long)divisor);
    
            int quotient = 0;
    
            while(absDividend >= absDivisor){
                long long tempDivisor = absDivisor;
                int multiple = 1;
    
                //get a bigger chunk if its still  less than dividend
                //for ex , 250 >= (12<<1) . 12 << 1 = 12 * 2^1 = 24, its true so for next time our divisor becomes 24 and multiple stores which multiple is it of actual divisor
                while(absDividend >= (tempDivisor<<1)){
                    tempDivisor<<=1;
                    multiple<<=1;
                }
    
                absDividend -= tempDivisor;
                quotient += multiple;
            }
            return (sign)?-quotient:quotient;
    
        }
    };

int main(){
    Solution sol1;
    cout<<sol1.divide(10,3);
    return 0;
}