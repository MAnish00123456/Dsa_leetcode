// Given an array of strings words and an integer k, return the k most frequent strings.
// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.

#include<iostream>
#include<unordered_map>
#include<queue>
#include<string>

class Solution {
    public:
        std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
    
            // function<bool(pair<string, int>, pair<string, int>)> custom_sort =
            //     [&](const pair<string, int>& v1, const pair<string, int>& v2) {
            //         if (v1.second == v2.second)
            //             return v1.first < v2.first;
            //         return v1.second > v2.second;
            //     };
    
            //for min heap , comparator
            auto cmp = [](auto const& v1, auto const& v2) {
                if (v1.second == v2.second)
                    return v1.first < v2.first;
                return v1.second > v2.second;
            };
    
            std::unordered_map<std::string, int> map;
            for (std::string str : words)
                map[str]++;
    
            // vector<pair<string, int>> Pairs(map.begin(), map.end());
    
            // sort(Pairs.begin(), Pairs.end(), custom_sort);
    
            // vector<string> Ans;
    
            // for (auto p : Pairs) {
            //     if (k == 0)
            //         break;
            //     Ans.push_back(p.first);
            //     k--;
            // }
    
            // return Ans;
    
            std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>,
                           decltype(cmp)>
                pq(cmp);
    
            for (auto& p : map) {
                pq.push(p);
                if (pq.size() > k)
                    pq.pop();
            }
            std::vector<std::string> Ans(k);
            for (int i = k - 1; i >= 0; i--) {
                Ans[i] = pq.top().first;
                pq.pop();
            }
            return Ans;
        }
    };

    int main(){
        std::vector<std::string>words = {"i","love","leetcode","i","love","coding"};
        int k = 3;
        Solution sol1;
        std::vector<std::string>Ans = sol1.topKFrequent(words,k);
        for(auto s : Ans)std::cout<<s<<" ";
        return 0;
    }