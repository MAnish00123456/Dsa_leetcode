// Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.

// The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).

// The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

// Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
// Output: 45

#include<iostream>
using namespace std;

class Solution {
    public:
        int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
            
            //total area = area of first rectangle + area of second rectangle - area of common region(As it got counted twice)
    
            //area of 1st triangle
            int width1 = ax2-ax1;
            int length1 = ay2-ay1;
            int area1 = length1*width1;
    
            //area of 2nd triangle
            int width2 = bx2-bx1;
            int length2 = by2-by1;
            int area2 = length2*width2;
    
            //area of common region
            int width3 = min(ax2,bx2) - max(ax1,bx1);
            int length3 = min(ay2,by2) - max(ay1,by1);
            //no common region
            if(width3 < 0 || length3 < 0){
                return area1 + area2;
            }
            int area3 = length3 * width3;
            
    
            int total_area = area1 + area2 - area3;
            return total_area;
        }
    };

int main(){
    Solution sol1;
    cout<<sol1.computeArea(-3,0,3,4,0,-1,9,2);
    return 0;
}