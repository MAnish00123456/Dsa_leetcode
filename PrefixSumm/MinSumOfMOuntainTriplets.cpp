//In this problem , we have given an array 'nums' in which we have to find a Mountain triplet of indices [i,j,k] which will satisfy the given condtion:-
//i>j>k and nums[i]<nums[j]>nums[k] , if this condition is satisfied then return the minimum sum of nums[i,j,k] that forms the mountain , 
//if no mountain triplet exists , return -1;

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int minimumSum(std::vector<int> &nums)
{
    int n = nums.size();
    int minSum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if ((nums[i] < nums[j]) && (nums[k] < nums[j])){
                    int sum = nums[i]+nums[j]+nums[k];
                    minSum = std::min(minSum,sum);
                }
            }
        }
    }
    if(minSum == INT_MAX) {return -1;}
    return minSum;
}


//optimal approach
//Use of prefix and suffix min TC - O(n) ,, isme we maitain 2 arrays for calculating min value for index j . ,, 
//Hum har index j ke liye best possible min value precompute krenge left nd right side se and ek prefixMin suffixMin nikalenge , 
//we will assume that we have currently the smallest num possible for the index from  all previous values and next values, then we will check for each nums[j]
//if it is greater than its previous and next value of prefixmin and suffixmin , then we will add those values
int OPminimumSum(std::vector<int> &nums){
int n = nums.size();
std::vector<int>PrefixMin(n) ; 
std::vector<int>SuffixMin(n);
PrefixMin[0]=nums[0];
SuffixMin[n-1]=nums[n-1];
for(int i = 1 ;i<n ; i++){
PrefixMin[i]=std::min(PrefixMin[i-1],nums[i]);
}
for(int j=n-2;j>0;j--){
    SuffixMin[j]=std::min(SuffixMin[j+1],nums[j]);
}
int ans = INT_MAX;
for(int j =1 ; j<n-1 ; j++){
    if((nums[j]>PrefixMin[j-1]) && (nums[j] > SuffixMin[j+1])){
        ans = std::min(ans,PrefixMin[j-1]+nums[j]+SuffixMin[j+1]);
    }
}
return ans==INT_MAX?-1:ans;

}


int main()
{
    std::vector<int> nums = {8, 6, 1, 5, 3};
    int sum = OPminimumSum(nums);
    std::cout << "Min sum : " << sum;
    return 0;
}