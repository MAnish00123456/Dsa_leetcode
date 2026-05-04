//Maximum subarray sum, nikalana hai given array se

//brute force method
// #include <iostream>
// #include <vector>
// #include<climits>
// int main(){
//     int sum=0;
//     int n=7;
//     // int arr[5]={1,2,3,4,5};
//     int arr[7]={3,-4,5,4,-1,7,-8};
//     //to print
//     for(int st=0;st<n;st++){
//        for(int end=st;end<n;end++){
//           for(int i=st;i<=end;i++){
//                std::cout<<arr[i]<<" ";
//             }
//              std::cout<<" ";
//          }
//          std::cout<<std::endl;
//      }

//  }
//  int maxsum=INT_MIN;
//  for(int st=0;st<n;st++){
//      int currsum=0;
//          for(int end=st;end<n;end++){
//              currsum+=arr[end];
//              maxsum=std::max(currsum,maxsum);
//          }
//     }
//  std::cout<<"max sum:"<<maxsum;
//  }

//kadane's algo
#include<iostream>
#include<climits>
#include<vector>

int MaxSum(std::vector<int> &nums){
    int currsum=0;
    int maxsum=INT_MIN;
    for(int val:nums){
        currsum+=val;
        maxsum=std::max(currsum,maxsum);
        if(currsum<0){
            currsum=0;
        }
    }
    return maxsum;
}
int main(){
    std::vector<int> Nums={1,2,3,-2,4,-5,7,8,-9};
    int maxsum=MaxSum(Nums);
    std::cout<<"maximum subaray sum is : "<<maxsum;
    return 0;
}