// Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10^n.

// Input: n = 2
// Output: 91
// Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99

#include<iostream>

class Solution {
    //it is a type of Permutation and Combination concept , where digits at each place are placed in such a way that they dont repeat again , if we include a digit at tens place , we cant use same digit later on ones place , making available digits less
    //it is similar to as what we did in our school

    //for ex , if n = 2.
    //so total digits we can use at tens place would be 9 out of 10 as we cant use digit '0' at tens place , as leading zero doesnt count , then at ones place we will also have 9 digits to use we include 0 here but not the digit we used previously.
    //that makes total count of size 2 number with unique digits as 9*9 = 81;
    //Now our answer also includes numbers with unique digits for size less than current size.
    //it means we will include numbers 0-9 , making total count 10 more.
    //final total = 81 + 10 = 91
public:
    int countNumbersWithUniqueDigits(int n) {
if(0 == n)return 1;
        int Ans = 10; // base answer when n = 1
        int possibledig = 9;//if n == 2 , at tens place we have possible 9 digits to use except 0 and then for ones place we only have 9 more digits available including 0 and excluding used digit at tens place
        int availabledig = 9;//remaining digits we have after using a digit previously in number
        for(int len = 2 ; len<=n && availabledig ; len++){
            possibledig*= availabledig;
            Ans+=possibledig;
            availabledig--;
        }
        return Ans;
    }
};

int main(){
    Solution sol1;
    int n = 4;
    int total_unique_nums = sol1.countNumbersWithUniqueDigits(n);
    std::cout<<total_unique_nums;
    return 0;
}