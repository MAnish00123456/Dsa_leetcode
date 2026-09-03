// You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
// Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
// Return the smallest index i at which either a row or a column will be completely painted in mat.

// Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
// Output: 3
// Explanation: The second column becomes fully painted at arr[3].

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
    public:
        int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat) {
            std::unordered_map<int,std::pair<int,int>>hash;
            int row = mat.size();
            int col = mat[0].size();
            
            for(int i = 0 ; i < row ; i++){
                for(int j = 0 ; j < col ; j++){
                    hash[mat[i][j]] = {i,j};
                }
            }
    
            // unordered_map<string,int>gridPainted;
            std::vector<int>rowCount(row,0);
            std::vector<int>colCount(col,0);
            int req_indice = -1;
            for(int i = 0 ; i < arr.size() ; i++){
                int val = arr[i];
                auto indices = hash[val];
                // string rowPattern = to_string(indices.first) +  "R";
                // string colPattern = to_string(indices.second) +  "C";
    
                // gridPainted[rowPattern]++;
                // gridPainted[colPattern]++;
    
                rowCount[indices.first]++;
                colCount[indices.second]++;
                // if(gridPainted[rowPattern] == col || gridPainted[colPattern] == row){
                //     req_indice = i;
                //     break;
                // }
                if(rowCount[indices.first] == col || colCount[indices.second] == row){
                    return i;
                }
            }
    
            // return req_indice;
            return -1;
        }
    };

int main(){
    Solution sol1;
    std::vector<int>arr = {2,8,7,4,1,3,5,6,9};
    std::vector<std::vector<int>>mat = {{3,2,5},{1,4,6},{8,7,9}};
    std::cout<<"First complete indice : "<<sol1.firstCompleteIndex(arr,mat);
    return 0;
}