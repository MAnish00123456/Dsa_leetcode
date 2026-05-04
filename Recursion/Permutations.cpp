// in this question ,we have given an array and we have to return all permutations for that array
// permutation is arrangement of elements , for n elements we have n! arrangements
// return all
// recursion + backtracking
//we gonna use original array to inplace calculate permutaions at each recursion call
#include <iostream>
#include <vector>
#include<algorithm>
void getallperms(std::vector<int> &nums, int idx, std::vector<std::vector<int>>& Ans)
{
    //Base case , when idx == size of array
    if(idx == nums.size()){
        Ans.push_back(nums);
        return;
    }
 
    //permutation + backtracking call
    for(int i = idx ; i<nums.size();i++){
        //inplace calculate permutaions
        std::swap(nums[idx] , nums[i]);
        //recursion call for next idx arrangement
        getallperms(nums,idx+1,Ans);

        //backtracking to last stack frame after our base case hit
        std::swap(nums[idx] , nums[i]);//we will make our array as we had it before base case hit , thats our whole assumption for inplace permutaion for next idx arrangement in stack frame
    }
}

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    std::vector<std::vector<int>> Ans;
    getallperms(nums, 0, Ans);
    return Ans;
}

int main()
{
    std::vector<int> nums = {1, 2 ,1};
    std::vector<std::vector<int>> Permutations = permute(nums);
    for (auto val : Permutations)
    {
        for (auto perm : val)
        {
            std::cout << perm;
        }
        std::cout << "\n";
    }
    return 0;
}