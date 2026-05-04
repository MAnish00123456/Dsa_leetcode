// 287
// Givean an integer array nums of size n+1 and range of integer values are from [1 to n]... for ex , size =5 , so n+1=5 , n=4 , range of integers [1 to 4],
// nums = { 1,2,3,4,3} with having a duplicate integer , that can vary from  frequency of 2 to n...

#include <iostream>
#include <vector>
#include <unordered_set>

// 1st Approach , we use an unordered_set to find the duplicate, ... Time complexity = O(n) and Space complexity = O(n)
int findDuplicate(std::vector<int> &Nums)
{
    int size = Nums.size() - 1;
    std::unordered_set<int> S;
    for (int i = 0; i <= size; i++)
    {
        if (S.find(Nums[i]) != S.end())
        {
            return Nums[i];
        }
        S.insert(Nums[i]);
    }
    return -1;
}

// 2nd Approach , we imagine our given array as Linked List ,,, where we consider each index as a 'Node' and value at that index as our pointer to 'Nextnode' ,,,
// We will use a Slow and Fast pointer approach in which our Slow pointer moves by 1 and our fast pointer moves by 2,,, By this approach we get Time complexity = O(n) and Space complexity = O(1)
// We will use do while loop for this approach and initialize our Slow and Fast pointer to Nums[0]
int OptimalfindDuplicate(std::vector<int> &nums)
{
    int size = nums.size() - 1;
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];       // increment by 1
        fast = nums[nums[fast]]; // increment by 2
    } while (slow != fast);
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow]; // increment by 1
        fast = nums[fast]; // increment by 1
    }

    return slow;
}

int main()
{
    // size = 5,, n = 4 ,, range [ 1 to 4 ] with duplicate integer 3
    std::vector<int> Nums = {3, 1, 3, 4, 2};
    int Duplicate = OptimalfindDuplicate(Nums);
    std::cout << " Duplicate integer in given array is : " << Duplicate << std::endl;
    return 0;
}