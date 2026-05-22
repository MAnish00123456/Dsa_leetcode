#include<iostream>

class Solution {
    public:
        int hammingWeight(int n) {
            int res = 0;   // Stores count of set bits (bits having value 1)
    
            // Iterate through all 32 bit positions of an integer
            // i represents current bit index (0 = least significant bit)
            for(int i = 0; i < 32; i++) {
    
                /*
                  Step 1: Shift number 'n' right by i positions
                  
                  Example:
                  n = 13  -> binary = 0000...1101
    
                  i = 0:
                  1101 >> 0 = 1101
    
                  i = 1:
                  1101 >> 1 = 0110
    
                  i = 2:
                  1101 >> 2 = 0011
    
                  Right shift moves desired bit to the last position.
                */
    
                /*
                  Step 2: Extract last bit using '& 1'
    
                  AND operation with 1 keeps only least significant bit.
    
                  Example:
                  0110 & 0001 = 0
                  0011 & 0001 = 1
    
                  If extracted bit is 1, current position contains a set bit.
                */
                if ((n >> i) & 1) {
                    res++;   // Increase count of set bits
                }
            }
    
            // Return total number of 1s present in binary representation
            return res;
        }
    };
    int main(){
        Solution sol1;
        int n = 11;
        int count = sol1.hammingWeight(n);
        std::cout<<count;
        return 0;
    }