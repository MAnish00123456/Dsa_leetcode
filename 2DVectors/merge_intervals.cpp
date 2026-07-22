// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
    public:
        std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    
         auto cmp = [](const std::vector<int>& n1 , const std::vector<int>& n2){
            return n1[0] < n2[0];
         }   ;
         sort(intervals.begin(),intervals.end(),cmp);
    
        std::vector<std::vector<int>>Ans;
        Ans.push_back(intervals[0]);
    
        for(int i = 1 ; i < intervals.size() ; i++){
            auto& last = Ans.back();
            auto& curr = intervals[i];
    
            if(last[1] >= curr[0]){
                last[1] = (last[1] > curr[1])?last[1]:curr[1];
            }else{
                Ans.push_back(curr);
            }
        }
    
         return Ans;
    
        }
    };

int main(){
    Solution sol1;
    std::vector<std::vector<int>>intervals = {{1,3},{2,6},{8,10},{15,18}};
    std::vector<std::vector<int>>Ans = sol1.merge(intervals);
    // Visualizes your 2D matrix on the console
    for (const auto& interval : Ans) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }
return 0;    
}