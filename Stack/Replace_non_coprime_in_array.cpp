// You are given an array of integers nums. Perform the following steps:

// Find any two adjacent numbers in nums that are non-coprime.
// If no such numbers are found, stop the process.
// Otherwise, delete the two numbers and replace them with their LCM (Least Common Multiple).
// Repeat this process as long as you keep finding two adjacent non-coprime numbers.
// Return the final modified array. It can be shown that replacing adjacent non-coprime numbers in any arbitrary order will lead to the same result.

// The test cases are generated such that the values in the final array are less than or equal to 108.

// Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) is the Greatest Common Divisor of x and y.

// Input: nums = [6,4,3,2,7,6,2]
// Output: [12,7,6]
// Explanation: 
// - (6, 4) are non-coprime with LCM(6, 4) = 12. Now, nums = [12,3,2,7,6,2].
// - (12, 3) are non-coprime with LCM(12, 3) = 12. Now, nums = [12,2,7,6,2].
// - (12, 2) are non-coprime with LCM(12, 2) = 12. Now, nums = [12,7,6,2].
// - (6, 2) are non-coprime with LCM(6, 2) = 6. Now, nums = [12,7,6].
// There are no more adjacent non-coprime numbers in nums.
// Thus, the final modified array is [12,7,6].
// Note that there are other ways to obtain the same resultant array.

#include<iostream>
#include<vector>
#include<stack>


class Solution {
    int gcd(int num1 , int num2){
        while(num2 != 0){
            int rem = num1%num2;
            num1 = num2;
            num2 = rem;
        }
        return num1;
    }
    int lcm(int num1 , int num2,int gcdNum){
            long long mul = (long long)num1 * (long long)num2;
            long long lcm = mul / gcdNum;
            return static_cast<int>(lcm);
    }
public:
    std::vector<int> replaceNonCoprimes(std::vector<int>& nums) {
        std::stack<int>st;
        for(int val : nums){
            // Lazily merge previously formed adjacent non-coprimes
            while(!st.empty() && st.size() >= 2){
                int num2 = st.top();st.pop();
                int num1 = st.top();
                int gcdofnum = gcd(num1,num2);
                if(gcdofnum > 1){
                    st.pop();
                    // Replace adjacent non-coprimes by their LCM
                    st.push(lcm(num1,num2,gcdofnum));
                }else{
                    // Current adjacent pair is coprime
                    st.push(num2);
                    break;
                }
            }
             // Current value will be processed in the next iteration
                st.push(val);
        }
// Handle any pending merges involving the last elements
        while(!st.empty() && st.size() >= 2){
           int num2 = st.top();st.pop();
                int num1 = st.top();
                int gcdofnum = gcd(num1,num2);
                if(gcdofnum > 1){
                    st.pop();
                    st.push(lcm(num1,num2,gcdofnum));
                }else{
                    st.push(num2);
                    break;
                } 
        }

        std::vector<int>Ans(st.size(),0);
        for(int i = Ans.size() -1 ; i >= 0 ; i--){
            Ans[i] = st.top();
            st.pop();
        }

        return Ans;
    }
};

int main(){
    std::vector<int> nums = {6,4,3,2,7,6,2};
    Solution sol1;
    std::vector<int> Ans = sol1.replaceNonCoprimes(nums);
    for(int val : Ans)std::cout<<val<<" ";
    return 0;
}