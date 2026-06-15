// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


#include<vector>
#include<iostream>
#include<unordered_map>
#include<functional>


class Solution {
    //custom hash function to store pair values as key
    //using operator overloading '()' , return xor values of both values acting as key

    //struct act as container for logic
    struct pair_hash{
        size_t operator()(const std::pair<int,bool>&v)const{
            return std::hash<int>{}(v.first)^std::hash<bool>{}(v.second);
        }
    };
public:
//first solution using hashmap
    int maxProfit(std::vector<int>& prices) {
        std::unordered_map<std::pair<int,bool>,int,pair_hash>Hashmap;
        //state defines buying or selling day
            //on buying day : after buying me move to next day
                            //or we can skip the day and move to other day to buy stock
            //on selling day : after selling the stock we move to day after tomorrow because of cooldown of        
                                // 1   day                
                                //or we can skip the day andd move to other day to sell stock

        //Map acts like a caching which stores the day and state of that as key and maxprofit in accordance tot hat day to simplify recursion

        //lambda function
       std::function<int(int,bool)>stock = [&](int i , bool buying) -> int {
            if(i >= prices.size())return 0;
            if(Hashmap.count({i,buying})) return Hashmap[{i,buying}];

            if(buying){
                int buy = stock(i+1 , !buying) - prices[i];
                int skip = stock(i+1 , buying);
                Hashmap[{i,buying}]=std::max(buy,skip);
            }else{
                int sell = stock(i+2 , !buying) + prices[i];
                int skip = stock(i+1 , buying);
                Hashmap[{i,buying}]=std::max(sell,skip);
            }
            return Hashmap[{i,buying}];
        };
        //start with day 1 and buying that stock
        return stock(0,true);
    }


    //another solution using 2d array , which stores number of days , and for each day the buying and selling state with maxprofit alongside
    int maxProfit1(std::vector<int>& prices){
        std::vector<std::vector<int>>Caching(prices.size(),std::vector<int>(2,-1));

        std::function<int(int,bool)>Stock = [&](int day ,bool buying) -> int{
            if(day >= prices.size())return 0;

            if(Caching[day][buying] != -1)return Caching[day][buying];

            if(buying){
                int buy = Stock(day+1,!buying) - prices[day];
                int skip = Stock(day+1,buying);
                Caching[day][buying] = std::max(buy,skip);
            }else{
                int sell = Stock(day+2,!buying) + prices[day];
                int skip = Stock(day+1,buying);
                Caching[day][buying] = std::max(sell,skip);
            }
            return Caching[day][buying];
        };
        return Stock(0,true);
    }
};

int main(){
    std::vector<int> prices = {1,2,3,0,2};
    Solution sol1;
    int profit = sol1.maxProfit1(prices);
    std::cout<<profit<<std::endl;
    return 0;
}