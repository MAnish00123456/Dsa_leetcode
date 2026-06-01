// A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.

// The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.

// For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.
// Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the minimum cost of buying all the candies

#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<numeric>
class Solution {
    public:
        int minimumCost(std::vector<int>& cost) {
            int Mincost =0;
            if(cost.size()<3)return accumulate(cost.begin(),cost.end(),Mincost);
            //sorting in descending order is helpful for this approach as cost of choosing the 3rd candy will always be lower thanfirst 2 candies , so we can get it for free
            std::sort(cost.begin(),cost.end(),std::greater<int>());
            for(int i = 0 ; i < cost.size() ; i++){
                //for every pair of 3 candies , pay for first 2 candies and then get 3rd one for free
                if(i%3 != 2){
                    Mincost+=cost[i];
                }
            }
            return Mincost;
            }
    };

    int main(){
        std::vector<int>cost = {1,2,3};
        Solution sol1;
        int minCost = sol1.minimumCost(cost);
        std::cout<<minCost<<std::endl;
        return 0;
    }