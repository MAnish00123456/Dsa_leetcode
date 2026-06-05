// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

#include<iostream>
#include<vector>
#include<stack>

class Solution {
    public:
        std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    
            // Stores indices of days having temperatures in
            // strictly decreasing order from bottom to top.
            std::stack<int> st;
    
            std::vector<int> Ans(temperatures.size());
    
            // Traverse from right to left because we need to find
            // the next warmer day on the right side.
            for (int i = temperatures.size() - 1; i >= 0; i--) {
    
                // Remove all days that are not warmer than the
                // current day since they can never be the answer.
                while (!st.empty() &&
                       temperatures[st.top()] <= temperatures[i]) {
                    st.pop();
                }
    
                // If stack is empty, no warmer day exists.
                // Otherwise, stack top represents the nearest
                // future day having a higher temperature.
                Ans[i] = st.empty() ? 0 : st.top() - i;
    
                // Store current day's index so it can act as a
                // candidate warmer day for previous days.
                st.push(i);
            }
    
            return Ans;
        }
    };

    int main(){
        std::vector<int> temps = {73,74,75,71,69,72,76,73};
        Solution sol1;
        std::vector<int> Ans = sol1.dailyTemperatures(temps);
        for(int val : Ans)std::cout<<val<<" ";
        return 0;
    }