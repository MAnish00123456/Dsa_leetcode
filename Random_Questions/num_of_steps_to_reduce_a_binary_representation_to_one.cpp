// Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

// If the current number is even, you have to divide it by 2.

// If the current number is odd, you have to add 1 to it.

// It is guaranteed that you can always reach one for all test cases.

// Input: s = "1101"
// Output: 6
// Explanation: "1101" corressponds to number 13 in their decimal representation.
// Step 1) 13 is odd, add 1 and obtain 14. 
// Step 2) 14 is even, divide by 2 and obtain 7.
// Step 3) 7 is odd, add 1 and obtain 8.
// Step 4) 8 is even, divide by 2 and obtain 4.  
// Step 5) 4 is even, divide by 2 and obtain 2. 
// Step 6) 2 is even, divide by 2 and obtain 1. 


#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
    private:
        // Because the string is reversed, index 0 is now the LEAST significant bit.
        // We walk forward from the current position 'start_idx' to handle the carry.
        void add1tostring(string& s, int start_idx) {
            for (int i = start_idx; i < s.size(); i++) {
                if (s[i] == '1') {
                    s[i] = '0';
                } else {
                    s[i] = '1';
                    return; // Carry is absorbed, we can stop
                }
            }
            // If the loop finished, it means we had an overflow (e.g., 111 -> 000)
            // Pushing to the back of a reversed string is O(1) time!
            s.push_back('1');
        }
    
    public:
        int numSteps(string s) {
            // Reverse the string first. Example: "1101" becomes "1011"
            reverse(s.begin(), s.end());
            
            int cnt = 0;
            int i = 0; // Tracks our current least significant bit position
    
            // Loop runs until only the last bit (which is at the end of the string now) remains
            while (i < s.size() - 1) {
                // Odd case
                if (s[i] == '1') {
                    add1tostring(s, i);
                    cnt++; // Step for addition
                } 
                // Even case
                else {
                    // Instead of popping from the front (expensive), 
                    // we just move our index pointer forward by 1 (virtually dropping the bit)
                    i++; 
                    cnt++; // Step for division
                }
            }
            return cnt;
        }
    };

int main(){
    Solution sol1;
    cout<<sol1.numSteps("1101");
    return 0;
}