// There is a broken calculator that has the integer startValue on its display initially. In one operation, you can:

// multiply the number on display by 2, or
// subtract 1 from the number on display.
// Given two integers startValue and target, return the minimum number of operations needed to display target on the calculator.

// Input: startValue = 3, target = 10
// Output: 3
// Explanation: Use double, decrement and double {3 -> 6 -> 5 -> 10}.

#include<iostream>
using namespace std;

class Solution {
    public:
        int brokenCalc(int startValue, int target) {
            if(target <= startValue)return startValue-target;
            int  min_ops = 0;
            while(target != startValue){
                if(target%2 == 0 && target > startValue){
                    target >>=1;
                    min_ops++;
                }else{
                    target += 1;
                    min_ops++;
                }
            }
            return min_ops;
        }
    };

int main(){
    Solution sol1;

    cout<<sol1.brokenCalc(5,8);
    return 0;
}