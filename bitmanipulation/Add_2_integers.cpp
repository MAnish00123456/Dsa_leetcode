#include<iostream>

class Solution {
    public:
        int getSum(int a, int b) {
    
            /*
            Idea: Perform addition using bitwise operations
    
            XOR (^)  -> gives sum without carry
            AND (&)  -> gives carry positions
    
            Then shift carry left and repeat until no carry remains
    
            -------------------------------------------------------
    
            Example:
            a = 9  -> 1001
            b = 11 -> 1011
    
            Step 1:
            a ^ b  = 0010  (sum without carry)
            a & b  = 1001  (carry positions)
    
            carry << 1 = 10010
    
            Now:
            a = 0010
            b = 10010
    
            Repeat until b becomes 0 (no carry left)
    
            -------------------------------------------------------
    
            Why it works:
            - XOR adds bits ignoring carry
            - AND finds where carry is generated
            - shifting carry moves it to correct position
            */
    
            while(b != 0){
    
                // find carry (common set bits)
                unsigned temp = (a & b);
    
                // sum without carry
                a = a ^ b;
    
                // shift carry to next higher bit
                b = temp << 1;
            }
    
            return a;
        }
    };
    int main(){
        Solution sol1;
        int sum = sol1.getSum(9,11);
        std::cout<<"sum : "<<sum;
        return 0;
    }