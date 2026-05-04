// in this problem we have given an array of integers named ' nums ' in which we have to find unique quadruplets whose sum is equal to our given target
// We have to return all quadruplets such that all indices of numbers are different

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

// Brute force method ,, we use 4 nested for loops ,, verified
std::vector<std::vector<int>> Bruteforce4sum(std::vector<int> &nums, int target)
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
                for (int l = k + 1; l < n; l++)
                {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                    {
                        std::vector<int> Quad = {{nums[i], nums[j], nums[k], nums[l]}};
                        std::sort(Quad.begin(), Quad.end());
                        if (S.find(Quad) == S.end())
                        {
                            S.insert(Quad);
                            Ans.push_back(Quad);
                        }
                    }
                }
            }
        }
    }
    return Ans;
}

// optimal approach ,,  hashing approach
std::vector<std::vector<long long>> hashing4sum(std::vector<long long> &nums, long long target)
{
    int n = nums.size();
    std::set<std::vector<long long int>> S;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            std::set<long long>S1;
            for (int k = j + 1; k < n; k++)
            {
                long long d = (long long)target - nums[i] - nums[j] - nums[k];
                if(S1.find(d) != S1.end()){
                    std::vector<long long int>Quad={{nums[i],nums[j],nums[k],d}};
                    std::sort(Quad.begin(),Quad.end());
                    S.insert(Quad);
                }
                S1.insert(nums[k]);
            }
        }
    }
   
    return std::vector<std::vector<long long>>(S.begin(),S.end());
}

//Most optimal approach ,, two pointers
std::vector<std::vector<long long>> OptimizedApproach4sum(std::vector<long long> &nums, long long target){
    std::sort(nums.begin(),nums.end());
    int n = nums.size();
    std::vector<std::vector<long long>>Ans;
    // std::set<std::vector<long long>>S;
    for(int i=0;i<n;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j] == nums[j-1]){continue;}
            int k=j+1 , l=n-1;
            while(k<l){
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if(sum<target){
                    k++;
                }
                else if(sum>target){
                    l--;
                }
                else{
                    std::vector<long long>Quad = {{nums[i],nums[j],nums[k],nums[l]}};
                    // if(S.find(Quad) == S.end()){
                        // S.insert(Quad);
                        Ans.push_back(Quad);
                    // }
                    k++ , l--;
                    while(k<l && nums[k] == nums[k-1]){
                        k++;
                    }

                }
            }
        }
    }
    return Ans;
}

int main()
{
    std::vector<long long> nums = {2,2,2,2,2};
    std::vector<int> nums1 = {1,0,-1,0,-2,2};
    long long target = 8;
    std::vector<std::vector<int>> Ans1 = Bruteforce4sum(nums1, target);
    std::vector<std::vector<long long>> Ans2 = hashing4sum(nums, target);
    std::vector<std::vector<long long>> Ans3 = OptimizedApproach4sum(nums, target);
    std::cout<<"Brute force Answer : "<<std::endl;
    for (int i = 0; i < Ans1.size(); i++)
    {
        std::cout << "[";
        for (int j = 0; j < Ans1[i].size(); j++)
        {

            std::cout << Ans1[i][j] << " ";
        }
        std::cout << "]";
        std::cout << "\n";
    }
    std::cout<<"\n";
    std::cout<<"Optimal hashing Answer : "<<std::endl;
    for (int i = 0; i < Ans2.size(); i++)
    {
        std::cout << "[";
        for (int j = 0; j < Ans2[i].size(); j++)
        {

            std::cout << Ans2[i][j] << " ";
        }
        std::cout << "]";
        std::cout << "\n";
    }
    std::cout<<"\n";
    std::cout<<"Most optimized 2pointer Answer : "<<std::endl;
    for (int i = 0; i < Ans3.size(); i++)
    {
        std::cout << "[";
        for (int j = 0; j < Ans3[i].size(); j++)
        {

            std::cout << Ans3[i][j] << " ";
        }
        std::cout << "]";
        std::cout << "\n";
    }
    std::cout<<"\n";
    return 0;
}