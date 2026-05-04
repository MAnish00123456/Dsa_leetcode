

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
// TC - O(n.k)
std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    int n = nums.size();
    std::vector<int> Arr, Ans;
    if (k <= 0)
    {
        Ans.push_back(0);
        return Ans;
    }
    for (int i = 0; i < k; i++)
    {
        Arr.push_back(nums[i]);
    }
    int maxE = *max_element(Arr.begin(), Arr.end());
    Ans.push_back(maxE);
    int l = 0;
    for (int j = k; j < n; j++)
    {
        Arr.push_back(nums[j]);
        l++;
        int Max = *max_element(Arr.begin() + l, Arr.end());
        Ans.push_back(Max);
    }
    return Ans;
}

// optimal , using deque
std::vector<int> OmaxSlidingWindow(std::vector<int> &nums, int k)
{
    std::deque<int> dq; // used deque (monotonic queue to only store maximum value for each window in the start)
    std::vector<int> Ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && dq.front() == i - k)
        {
            // removing our first element index if our window size is achieved
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            // removing elements from last if our current element is maximum , to store only maximum values in start
            dq.pop_back();
        }
        dq.push_back(i); // if no condition matches from above , we simply store our current value index
        if (i >= k - 1)
        {
            // pushing maximum value in each window to ans array
            // we have pushed our maximum value index in start of our deque
            Ans.push_back(nums[dq.front()]);
        }
    }
    return Ans;
}
int main()
{
    std::vector<int> nums = {1,3,-1,-3,5,3,6,7};
    // std::vector<int> nums = {1};
    // std::vector<int> nums = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    // std::vector<int> nums = {5, 1, 3, 4, 2};
    int k = 3;
    std::vector<int> MaxAns = OmaxSlidingWindow(nums, k);
    for (int val : MaxAns)
    {
        std::cout << val << "\t";
    }
    return 0;
}