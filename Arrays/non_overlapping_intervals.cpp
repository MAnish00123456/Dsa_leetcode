// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

// Example 1:

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            
            int ans = 0;
            sort(begin(intervals),end(intervals),[](auto& I1 , auto&  I2){
                return I1[1] < I2[1];
            });
    
            pair<int,int>last;
            for(int i = 0 ; i < intervals.size() ; i++){
                if(i == 0){
                    last = {intervals[0][0],intervals[0][1]};
                }else{
                    auto curr = intervals[i];
                    if(last.second > curr[0]){
                        ans++;
                    }else{
                        last ={curr[0],curr[1]};
                    }
                }
            }
            return ans;
        }
    };

    
int main() {
    vector<vector<int>>intervals = {{1,2},{2,3},{3,4},{1,3}};
    Solution sol1;
    cout<<sol1.eraseOverlapIntervals(intervals);
    return 0;

}