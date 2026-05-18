// You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

// The ith item is said to match the rule if one of the following is true:

// ruleKey == "type" and ruleValue == typei.
// ruleKey == "color" and ruleValue == colori.
// ruleKey == "name" and ruleValue == namei.
// Return the number of items that match the given rule.

#include<iostream>
#include<string>
#include<vector>

class Solution {
    public:
        int countMatches(std::vector<std::vector<std::string>>& items, std::string ruleKey,
                         std::string ruleValue) {
                            int idx = 0;
                            if(ruleKey == "color")idx=1;
                            if(ruleKey == "name")idx=2;
                            int count = 0;
                            for(auto& row : items){
                                if(row[idx] == ruleValue){
                                    count++;
                                }
                            }
                            return count;
        }
    };

 int main(){
    Solution sol1;
    std::string ruleKey = "color";
    std::string ruleValue = "silver";
    std::vector<std::vector<std::string>>items = {{"phone","blue","pixel"},{"computer","silver","lenovo"},{"phone","gold","iphone"}};
int count = sol1.countMatches(items,ruleKey,ruleValue);
std::cout<<count;
return 0;
 }