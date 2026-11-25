// Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.

// There is one laser beam between any two security devices if both conditions are met:

// The two devices are located on two different rows: r1 and r2, where r1 < r2.
// For each row i where r1 < i < r2, there are no security devices in the ith row.
// Laser beams are independent, i.e., one beam does not interfere nor join with another.

// Return the total number of laser beams in the bank.

// Input: bank = ["011001","000000","010100","001000"]
// Output: 8
// Explanation: Between each of the following device pairs, there is one beam. In total, there are 8 beams:
//  * bank[0][1] -- bank[2][1]
//  * bank[0][1] -- bank[2][3]
//  * bank[0][2] -- bank[2][1]
//  * bank[0][2] -- bank[2][3]
//  * bank[0][5] -- bank[2][1]
//  * bank[0][5] -- bank[2][3]
//  * bank[2][1] -- bank[3][2]
//  * bank[2][3] -- bank[3][2]
// Note that there is no beam between any device on the 0th row with any on the 3rd row.
// This is because the 2nd row contains security devices, which breaks the second condition

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int numberOfBeams(vector<string>& bank) {
            vector<string>newBank;
    
            //create new array of strings only for the ones which have securtiy systems in them, as we dont want any string with only 0
    
            for(string& s : bank){
                if(s.find('1') != string::npos){
                    newBank.push_back(s);
                }
            }
    
            //if we dont find any string having value 1 or only one string , ans is 0
            if(newBank.size() <= 1)return 0;
            
            //count number of 1's in first row
            int prev_row_count = count(begin(newBank[0]),end(newBank[0]),'1');
    
            int ans = 0;
    
            //traverse  from 2nd row
            for(int i = 1 ; i < newBank.size() ; i++){
                //count 1's in this row
                int crnt_row_count = count(begin(newBank[i]),end(newBank[i]),'1');
                //why prev_row_count * crnt_row_count , because for each 1 in crnt row every single 1 in previous row can point towards it , so we find the total counts using simple maths
                ans += (prev_row_count*crnt_row_count);
                prev_row_count = crnt_row_count;
            }
    
            return ans;
        }
    };

int main(){
    vector<string>bank = {"011001","000000","010100","001000"};
    Solution sol1;
    cout<<sol1.numberOfBeams(bank);
    return 0;

}