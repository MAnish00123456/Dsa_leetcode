// Write an algorithm to determine if a number n is happy.
// A happy number is a number defined by the following process:
// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.
#include<iostream>
#include<set>

//similar as cycle detection thinking
class Solution {
    int getNextnum(int n) {
        int output = 0;
        while (n) {
            int dig = n % 10;
            output += dig * dig;
            n /= 10;
        }
        return output;
    }

public:
    bool isHappy(int n) {
        // if following the procedure given in the description , at any point
        // when we encounter a number which is equal to our given 'n' , that
        // means the steps will repeat themselves (like a loophole) and will
        // never satisfy the condition in those situation , we will simply
        // return false; and  to track this thing we will use a set to store
        // already seen numbers
        std::set<int> Seen;
        while (Seen.find(n) == Seen.end()) {
            Seen.insert(n);
            //used to generate next number according to our description
            n = getNextnum(n);
            if (n == 1) {
                return true;
            }
        }
        return false;
    }
};
int main(){
    int n = 19;
    Solution sol1;
    if(sol1.isHappy(n)){
        std::cout<<n<<" is a happy number"<<std::endl;
    }
    else{
        std::cout<<n<<" is not a happy number"<<std::endl;
    }
    return 0;
}