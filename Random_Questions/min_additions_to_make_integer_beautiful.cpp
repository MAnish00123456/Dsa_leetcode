// You are given two positive integers n and target.
// An integer is considered beautiful if the sum of its digits is less than or equal to target.
// Return the minimum non-negative integer x such that n + x is beautiful. The input will be generated such that it is always possible to make n beautiful.

// Input: n = 16, target = 6
// Output: 4
// Explanation: Initially n is 16 and its digit sum is 1 + 6 = 7. After adding 4, n becomes 20 and digit sum becomes 2 + 0 = 2. It can be shown that we can not make n beautiful with adding non-negative integer less than 4.


#include<iostream>

class Solution {
    long long findsum(long long n) {
        long long sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    long long makeIntegerBeautiful(long long n, long long target) {
        long long OrigNum = n;
        long long base = 1; // ones ,tens ,hundreds , like this
        while (findsum(n) > target) {
            n = n / 10 +
                1; // as we want to  make our last digit to 0 , we cn possibly do
                   // it by making it equal to 10 as oour digit would be btw 1-9, so
                   // it means we need to add 1 to remaining num last digit as carry

            base *= 10; // update base
        }
        // we will get a number whose digit sum will be less than target , and
        // till that we will also get our base value to determine at which
        // level(tens , hundreds , thousands) we able to achieve solution
        // we will multiple remaining num with the base and subtract it with out
        // orig num which will tell us how many additions we did

        return n * base - OrigNum;
    }
};

int  main(){
    Solution  sol1;
    int n = 16;
    int target = 6;
    int minSteps = sol1.makeIntegerBeautiful(n,target);
    std::cout<<minSteps;
    return 0;
}