

#include<iostream>
#include<vector>
#include<algorithm>
class ArraySum{
  public:
  std::vector<int> addToArrayForm(std::vector<int>& nums, int k)  {
    if(k <= 0) return nums;
    int n = nums.size();
    int sum = 0;
    for(int i : nums){
        sum = sum*10 + i;
    }
    sum +=k;
    std::vector<int> res ;
    while(sum != 0){
        int dig = sum%10;
        res.push_back(dig);
        sum=sum/10;
    }
    std::reverse(res.begin(),res.end());
    return res;
  }
//best approach
  std::vector<int> NaddToArrayForm(std::vector<int>& nums, int k){
    if (k <= 0)
    return nums;
int i = nums.size() - 1;
while (i >= 0 || k > 0) {
    if (i >= 0) {
        k = k + nums[i];
        nums[i] = k % 10;
        k = k / 10;
        i--;
    }

    else {
        nums.insert(nums.begin(), k % 10);
        k = k / 10;
    }
}
return nums;
  }

};

int main(){
ArraySum ASum1;
// std::vector<int> nums = {1,2,0,0};
std::vector<int> nums = {2,1,5};
// int k = 34;
int k = 806;
std::vector<int> Rsum = ASum1.NaddToArrayForm(nums,k);
for(int val : Rsum){
    std::cout<<val<<" ";
}
return 0;
}