// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6 , enclosed withing #
//Matrix:
// 1 0 1 0 0
// 1 0 #1 1 1#
// 1 1 #1 1 1#
// 1 0 0 1 0

//we can breakdown this problem , by taking row by row values/ we can take a row and make a height array out of it and as our rows are incremented , we can increase these heights for particular columns and treat the
//array of fheight as a histogram and find max ractangle in histogram

#include<iostream>
#include<stack>
#include<vector>

class Solution {
    int LargestRectangleInHistogram(std::vector<int>& height){
        std::stack<int>st;

        std::vector<int>Leftmin(height.size(),-1);
        std::vector<int>rightmin(height.size(),-1);

        for(int i = 0 ; i < height.size() ; i++){
            while(!st.empty() && height[st.top()] >= height[i])st.pop();
            Leftmin[i] = st.empty()?-1:st.top();
            st.push(i);
        }

        st = {};
        int n = height.size();
        for(int i = height.size() - 1 ; i >= 0 ; i--){
            while(!st.empty() && height[st.top()] >= height[i])st.pop();
            rightmin[i] = st.empty()?n:st.top();
            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0 ; i < height.size() ; i++){
            maxArea = std::max(maxArea , height[i] * (rightmin[i] - Leftmin[i] - 1));
        }
        return maxArea;
    }
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
       int rows = matrix.size();
       int cols = matrix[0].size();
        int maxArea = 0;
       std::vector<int>height(cols,0);//think of each row as a separate array , and values represents bar size 
       //as progressively goin to other rows , genreally increase height of the bar but resets to 0 if base value is 0

       for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            if(matrix[i][j] == '1'){
                height[j] += 1;
            }else{
                height[j] = 0;
            }
        }
        maxArea = std::max(maxArea , LargestRectangleInHistogram(height));
       }
       return maxArea;
    }
};

int main(){
    std::vector<std::vector<char>> Matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    Solution sol1;
    int maxArea = sol1.maximalRectangle(Matrix);
    std::cout << maxArea;
    return 0;
}