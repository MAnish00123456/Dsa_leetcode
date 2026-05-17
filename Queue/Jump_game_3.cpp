// Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.
#include<iostream>
#include<queue>
#include<vector>

class Solution {
    public:
        bool canReach(std::vector<int>& nums, int start) {
            // for each index , we have 2 choices , either go right or go left.
            // to prevent from recursive loop , we can perform bfs , as each index
            // acts as a graph node which have two branches , and we used bfs
            // because we need to check if any particular node satisfies our
            // condition rather than using dfs to start from end node
            int n = nums.size();
            // maintain a queue as bfs uses queue to store its next neighbour nodes
            // that are to be evaulated
            std::queue<int> Q;
            // a visited matrix to mark visited indices , so we dont fall in
            // infinite  loop
            std::vector<bool> Visited(n, false);
            // push starting node to queue to evaluate it
            Q.push(start);
            // runs until we evaluate each index
            while (!Q.empty()) {
                int idx = Q.front();
                Q.pop();
    
                if (idx < 0 || idx >= n || Visited[idx])
                    continue;
    
                if (nums[idx] == 0)
                    return true;
    
                Visited[idx] = true;
    
                Q.push(idx + nums[idx]);
                Q.push(idx - nums[idx]);
            }
            return false;
        }
    };

    int main(){
        std::vector<int> nums = {4,2,3,0,3,1,2};
        int st = 5;
        Solution sol1;
        if(sol1.canReach(nums,st))std::cout<<"possible";
        else std::cout<<"impossible";
        return 0;
    }