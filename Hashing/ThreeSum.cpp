// in this problem we have given an array nums in which we have to find pair of 3 elements that add up to 0 and return them in ans array .
// the pairs must be unique means no permutation of same pairs and no same elements at same index.

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

// Brute force approach , TC - O(n^3logn)
// we use 3 nested for loops and based on condition return them
std::vector<std::vector<int>> BruteForce3sum(std::vector<int> &nums)
{
    int n = nums.size();
    std::vector<std::vector<int>> Ans;
    std::set<std::vector<int>> S;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    std::vector<int> Triplet = {{nums[i], nums[j], nums[k]}};
                    std::sort(Triplet.begin(), Triplet.end());
                    if (S.find(Triplet) == S.end())
                    {
                        S.insert(Triplet);
                        Ans.push_back(Triplet);
                    }
                }
            }
        }
    }

    return Ans;
}

// Optimal approach , we use hashing based approach , TC = O(n^2logn)
// We know a + b + c = 0 ,, so we cqan alter it as b + c = -q,, -a can be seen as target,, we use set to find our third value;
std::vector<std::vector<int>> Optimal3sum(std::vector<int> &nums)
{
    int n = nums.size();
    std::set<std::vector<int>> UniqueTrip;
    for (int i = 0; i < n; i++)
    {
        int target = -nums[i];
        std::set<int> S;
        for (int j = i + 1; j < n; j++)
        {
            int c = target - nums[j];
            if (S.find(c) != S.end())
            {
                std::vector<int> Trip = {{nums[i], nums[j], c}};
                std::sort(Trip.begin(), Trip.end());
                UniqueTrip.insert(Trip);
            }
            S.insert(nums[j]);
        }
    }
    return std::vector<std::vector<int>>(UniqueTrip.begin(), UniqueTrip.end());
}


//Most optimal Approach
//use of two pointers ,, we fix one value then a two pointer approach on remaining array 
std::vector<std::vector<int>> MostOptimal3sum(std::vector<int> &nums){
int n = nums.size();
 std::vector<std::vector<int>> UniqueTrip;
std::sort(nums.begin(),nums.end());
for(int i =0 ; i<n ; i++){
    if(i>0 && nums[i] == nums[i-1]) continue;
    int j = i+1 , k=n-1;
    while(j<k){
        int sum = nums[i]+nums[j]+nums[k];
        if(sum<0){j++;}
        else if(sum>0){k--;}
        else{
             std::vector<int> Trip = {{nums[i], nums[j], nums[k]}};
             UniqueTrip.push_back(Trip);
             j++;
             k--;
             while(j<k && nums[j] == nums[j-1]){
                j++;
             }
        }
    }
}
return UniqueTrip;
}

int main()
{
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> Ans = MostOptimal3sum(nums);
    for (int i = 0; i < Ans.size(); i++)
    {
        std::cout << "[";
        for (int j = 0; j < Ans[i].size(); j++)
        {

            std::cout << Ans[i][j] << " ";
        }
        std::cout << "]";
        std::cout << "\n";
    }
    return 0;
}