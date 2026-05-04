#include<iostream>
#include<vector>
#include<cmath>
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> newarr;
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<nums2[j]){
                newarr.push_back(nums1[i]);
                i++;
            }
            else{
                newarr.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            newarr.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            newarr.push_back(nums2[j]);
            j++;
        }
    int n=newarr.size();
    if(n%2==0) {
        return (newarr[(n-1)/2]+ newarr[n/2])/2.0 ;
    }
        else{
            
            return newarr[floor(n/2)];
        }
    }
int main(){
    std::vector<int> nums1={1,2};
    std::vector<int> nums2={3,4};
    auto median=findMedianSortedArrays(nums1,nums2);
    std::cout<<"Median:"<<median<<std::endl;
}