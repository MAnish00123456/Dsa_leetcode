// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.


#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
class Solution {
    //if we include our current bar and want to find max histogram area by including current bar, we need to find the width as height is fixed now.
    //for height , we will check till which index in left our histogram can be expanded by including current height , similaarly in right side.
    //the problem transistioned into finding for just next smaller and just prev smaller heights for each bar 
    //because these will act as our boundary limitation for each bar.
    //if we dont find any next smaller height for current bar , we will fix it to last index height for limiting boundary.
    //use of monotonic increasing stack where our top > bottom , pop top from stack if current height is smaller thn height on top of stack
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        std::stack<int>st;
        std::vector<int>Nextsmaller(heights.size());
        std::vector<int>Prevsmaller(heights.size());

        for(int i = n-1 ; i>= 0 ; i--){
            while(!st.empty() && heights[st.top()] >= heights[i])st.pop();
            Nextsmaller[i]=st.empty()?n:st.top();
            st.push(i);
        }

        st = {};
        
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i])st.pop();
            Prevsmaller[i]= st.empty()?-1:st.top();
            st.push(i);
        }

        for(int i = 0 ; i < n ; i++){
            maxArea = std::max(maxArea , heights[i] * (Nextsmaller[i] - Prevsmaller[i] -1));
        }
        return maxArea;
    }
};

int main(){
    std::vector<int> heights = {2,1,5,6,2,3};
    Solution sol1;
    int maxArea = sol1.largestRectangleArea(heights);
    std::cout<<maxArea;
    return 0;
}