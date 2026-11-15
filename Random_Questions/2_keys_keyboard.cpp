// There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

// Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
// Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

// Input: n = 3
// Output: 3
// Explanation: Initially, we have one character 'A'.
// In step 1, we use Copy All operation.
// In step 2, we use Paste operation to get 'AA'.
// In step 3, we use Paste operation to get 'AAA'.


#include<iostream>
using namespace std;
#include<vector>


class Solution {

    public:
        int minSteps(int n) {
            //for ex - 4
            //we have 'A' at first , we first copy it (1) then paste it (2) , becomes 'AA' , then again we copy it(3) , then paste it
            //(4) , becomes 'AAAA'. answer = 4;
            //but wait , 4 can be written in terms of prime factors , 2*2, the sum of these 2+2 is the answer
    
            //for ex - n = 9
            //'A' , copy it (1) , paste it 'AA' (2) , copy it (3) , paste it 'AAAA' (4), copy it (5) , paste it 'AAAAAAAA' but wait we cant get answer like that , so we revert back and we get to know that from 4rth step or 2nd step , we cant get odd numbers of 'A' , only option left is to paste 'A' again and again till u get a odd batch of 'A's then copy and paste it until u get 9  'A' , so it would be total of 6 times
            //'A' -> (1) ->  'AA'(2) -> 'AAA'(3) -> (4) -> 'AAAAAA'(5) ->'AAAAAAAAA'(6)
            // 9 can also be written as 3*3 , as prime factors ,  so 3+3 = 6 ans
            //Prime factorization question
            if(n == 1)return 0;
            vector<int>PrimeFactors;
    
            while(n%2 == 0){
                PrimeFactors.push_back(2);
                n/=2;
            }
            for(int i = 3 ; i*i <= n ; i+=2){
                while(n%i == 0){
                    PrimeFactors.push_back(i);
                    n/=i;
                }
            }
            if(n > 1)PrimeFactors.push_back(n);
            int min_steps = 0;
            for(int v : PrimeFactors)min_steps+=v;
            return min_steps;
        }
    };

int main(){
    Solution sol1;
    cout<<sol1.minSteps(9);
    return 0;
}