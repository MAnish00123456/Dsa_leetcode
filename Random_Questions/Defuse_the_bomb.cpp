// You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

// To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

// If k > 0, replace the ith number with the sum of the next k numbers.
// If k < 0, replace the ith number with the sum of the previous -k numbers.
// If k == 0, replace the ith number with 0.
// As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

// Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

// Input: code = [5,7,1,4], k = 3
// Output: [12,10,16,13]
// Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.

#include<iostream>
#include<vector>

class Solution {
    public:
        std::vector<int> decrypt(std::vector<int>& code, int k) {
            std::vector<int>decryption_code(code.size(),0);
            int sz = code.size();
            if(k==0){
                return decryption_code;
            }
    
            if(k > 0){
                for(int curr_idx = 0 ; curr_idx < code.size() ; curr_idx++){
                    int sum = 0;
                    for(int step = 1 ; step <= k ; step++){
                        int nxt_idx = (curr_idx + step)%sz;
                        sum+=code[nxt_idx];
                    }
                    decryption_code[curr_idx]=sum;
                }
                return decryption_code;
            }
            k = -k;
            for(int curr_idx = 0 ; curr_idx < code.size() ; curr_idx++){
                int sum = 0;
                for(int step = 1 ; step <= k ; step++){
                    int prev_idx = (curr_idx - (step%sz) + sz)%sz;
                    sum+=code[prev_idx];
                }
                decryption_code[curr_idx] = sum;
            }
            return decryption_code;
        }
    };

    int main(){
        std::vector<int>code = {5,7,1,4};
        int k = 3;
        Solution sol1;
        std::vector<int>decryption_key = sol1.decrypt(code,k);
        for(int val : decryption_key)std::cout<<val<<" ";
        return 0;
    }