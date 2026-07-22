// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
// Return intervals after the insertion.
// Note that you don't need to modify intervals in-place. You can make a new array and return it

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10]

#include<iostream>
#include<vector>

class Solution {
    public:
        std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals,std::vector<int>& newInterval) {
    
            if(intervals.size() == 0)return {newInterval};
    
            int low = 0 , high = intervals.size()-1;
            int stTime = newInterval[0];
            while(low <= high){
                int mid = low + (high-low)/2;
                if(intervals[mid][0] >= stTime){
                    high = mid-1;
                }else if(intervals[mid][0] < stTime){
                    low = mid + 1;
                }
            }
            intervals.insert(intervals.begin()+low,newInterval);
            std::vector<std::vector<int>>Ans;
            for(int i = 0 ; i < intervals.size() ; i++){
                auto& c = intervals[i];
                if(!Ans.empty() && Ans.back()[1] >= c[0]){
                    Ans.back()[1] = (Ans.back()[1] > c[1])?Ans.back()[1]:c[1];
                }else if(Ans.empty()||Ans.back()[1] < c[0]){
                    Ans.push_back(c);
                }
            }
            return Ans;
        }
    };

int main(){
    Solution sol1;
    std::vector<std::vector<int>>intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    std::vector<int> interval = {4,8};
    std::vector<std::vector<int>>Ans = sol1.insert(intervals,interval);
    // Visualizes your 2D matrix on the console
for (const auto& interval : Ans) {
    std::cout << "[" << interval[0] << ", " << interval[1] << "]\n";
}
return 0;
}