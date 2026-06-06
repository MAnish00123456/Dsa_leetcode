// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>

class Solution {
    public:
        std::string frequencySort(std::string s) {
            std::unordered_map<char,int>Hashmap;
    
            for(char ch : s)Hashmap[ch]++;
    
            std::priority_queue<std::pair<int,char>>pq;
    
            for(const auto& [key,val] : Hashmap){
            pq.push({val,key});
            }
            
    
            std::string Ans ="";
            while(!pq.empty()){
                auto top_elem = pq.top();
                Ans+=std::string(top_elem.first,top_elem.second);
                pq.pop();
            }
    
            return Ans;
        }
    };

    int main(){
        std::string str = "eeeabdsaas";
        Solution sol1;
        std::string ans = sol1.frequencySort(str);
        std::cout<<ans;
        return 0;
    }