// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

// Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// Output: 3
// Explanation:
// Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 4. Your tank = 4 - 1 + 5 = 8
// Travel to station 0. Your tank = 8 - 2 + 1 = 7
// Travel to station 1. Your tank = 7 - 3 + 2 = 6
// Travel to station 2. Your tank = 6 - 4 + 3 = 5
// Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
// Therefore, return 3 as the starting index.

#include<iostream>
#include<vector>

class Solution {
    public:
        int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
            int surplusGas = 0;//greedily check each station if we have enough gas to move forward
            //if at any index our surplusGas becomes negative , it means from last startIdx upto current ith index , we dont have enough fuel to complete journey
            //so update start to next index and check again
    
            //if our totgas available is less than totcost , i.e, less than total consumption of gas , we cant find solution hence -1
            int totgas = 0;
            int totCost = 0;
            int startIdx = 0;
    
            for(int i = 0 ; i < gas.size() ; i++){
                totgas +=gas[i];
                totCost += cost[i];
                surplusGas += (gas[i] - cost[i]);
                if(surplusGas < 0){
                    startIdx = i + 1;
                    surplusGas = 0;
                }
            }
            return (totgas < totCost)?-1:startIdx;
        }
    };

int  main(){
    std::vector<int> gas = {1,2,3,4,5};
    std::vector<int> cost = {3,4,5,1,2};
    Solution sol1;
    std::cout<<"st index : "<<sol1.canCompleteCircuit(gas,cost);
    return 0;
}