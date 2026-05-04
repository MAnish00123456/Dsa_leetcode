/* given an array of integers and a target , we need to return indices of 2 nums that add up to target
only one solution exist and u cant repeat a single valule again*/
#include<iostream>
#include<unordered_map>
#include<vector>
//brute force
std::pair<int,int> BruteTwoSum(int matrix[],int size,int target){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(matrix[i]+matrix[j]==target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

std::vector<int> OptimalTwoSum(std::vector<int> matrix,int target){
    std::unordered_map<int,int> m;
    for(int i=0;i<=matrix.size()-1;i++){
        int first=matrix[i];
        int second=target-first;
        if(m.find(second)!=m.end()){
            return {i,m[second]};
        }
            m[first]=i;
    }
    return {-1,-1};
}
/*use of Unordered map for fast lookup for values
target=first+second
assume first=arr[i]
second=target-first and then we find this second value in map , if exists return its indices along with i
else store first value in map
m[first]=i;
*/
int main(){
    // int matrix[3]={3,2,4};
    int target=6;
    // int size=sizeof(matrix)/sizeof(matrix[0]);
    std::vector<int> matrix={3,2,4};
    std::vector<int> pair=OptimalTwoSum(matrix,target);
    // std::pair<int,int>p=BruteTwoSum(matrix,size,target);
    std::cout<<"[ ";
    for(int i=0;i<pair.size();i++){
        std::cout<<pair[i]<<" ";
    }
    std::cout<<"]";
    return 0;
}