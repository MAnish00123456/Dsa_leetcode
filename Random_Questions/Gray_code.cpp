// An n-bit gray code sequence is a sequence of 2n integers where:

// Every integer is in the inclusive range [0, 2n - 1],
// The first integer is 0,
// An integer appears no more than once in the sequence,
// The binary representation of every pair of adjacent integers differs by exactly one bit, and
// The binary representation of the first and last integers differs by exactly one bit.
// Given an integer n, return any valid n-bit gray code sequence.

#include<iostream>
#include<vector>

class Solution {
    public:
        std::vector<int> grayCode(int n) {
    
            /*
            ------------------------------------------------------------
            GOAL:
            Generate Gray Code sequence of n bits.
    
            Gray Code property:
            → Every consecutive number differs by exactly ONE BIT.
    
            Example (n = 2):
            00 → 01 → 11 → 10
            (only 1 bit changes each time)
    
            ------------------------------------------------------------
            KEY IDEA:
            Instead of constructing manually, we use a direct formula:
    
                Gray(i) = i ^ (i >> 1)
    
            where:
                i       = normal binary number
                i >> 1  = right-shifted version of i
                ^       = XOR operation
    
            ------------------------------------------------------------
            WHY THIS WORKS:
    
            XOR compares adjacent bits:
    
            Binary:    b3  b2  b1  b0
            Shifted:    0  b3  b2  b1
            --------------------------------
            Gray:      b3  b3^b2  b2^b1  b1^b0
    
            → Each Gray bit represents whether adjacent bits changed.
            → This guarantees only ONE BIT change between consecutive numbers.
    
            ------------------------------------------------------------
            */
    
            std::vector<int> result;   // stores final Gray code sequence
    
            /*
            Total number of Gray codes for n bits = 2^n
    
            Using bit shift:
                1 << n  → 2^n
    
            Example:
                n = 3 → 1 << 3 = 8
            */
            int num_codes = 1 << n;
    
            /*
            Iterate through all numbers from 0 to 2^n - 1
            Each number is converted into its Gray code equivalent.
            */
            for(int i = 0; i < num_codes; i++){
    
                /*
                CORE TRANSFORMATION:
    
                Step 1: Take number i
                Step 2: Right shift it → (i >> 1)
                Step 3: XOR both
    
                This gives corresponding Gray code value.
                */
                int gray = i ^ (i >> 1);
    
                /*
                Push computed Gray code into result array
                */
                result.push_back(gray);
            }
    
            /*
            Final result contains Gray code sequence in correct order.
            */
            return result;
        }
    };

    int main(){
        int n = 2;
        Solution sol1;
        std::vector<int>Graycode = sol1.grayCode(n);
        for(int val : Graycode){
            std::cout<<val<<"  ";
        }
        return 0;
    }