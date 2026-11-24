// You are playing a game with integers. You start with the integer 1 and you want to reach the integer target.

// In one move, you can either:

// Increment the current integer by one (i.e., x = x + 1).
// Double the current integer (i.e., x = 2 * x).
// You can use the increment operation any number of times, however, you can only use the double operation at most maxDoubles times.

// Given the two integers target and maxDoubles, return the minimum number of moves needed to reach target starting with 1.

// Input: target = 19, maxDoubles = 2
// Output: 7
// Explanation: Initially, x = 1
// Increment 3 times so x = 4
// Double once so x = 8
// Increment once so x = 9
// Double again so x = 18
// Increment once so x = 19

#include<iostream>
using namespace std;

class Solution {
    public:
        int minMoves(int target, int maxDoubles) {
    
            int min_moves = 0;
            while(target != 1){
                if(target % 2 == 0 && maxDoubles > 0){
                    target = target/2;
                    min_moves++;
                    maxDoubles--;
                }else if(target % 2 != 0){
                    target = target-1;
                    min_moves++;
                }else if(maxDoubles == 0){
                    min_moves += target-1;
                    return min_moves;
                }
            }
        return min_moves;
        }
    };

int main(){
    Solution sol1;
    cout<<sol1.minMoves(19,2);
    return 0;
}