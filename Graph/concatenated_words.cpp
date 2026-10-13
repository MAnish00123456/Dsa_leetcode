// Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

// A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necessarily distinct) in the given array.

 

// Example 1:

// Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
// "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

//can be done using tries , as we are only checking prefix
class Solution {
    // cache[i] will store: -1 (unvisited), 0 (false), 1 (true)
    vector<int> cache; 

    bool dfs(const string& word, int start, const unordered_set<string>& hash) {
        int n = word.size();
        
        // Base case: If we successfully matched prefixes up to the end of the word
        if (start == n) return true;
        
        // Return cached result if already calculated
        if (cache[start] != -1) return cache[start];

        // Try all split points from the current start index
        for (int i = start + 1; i <= n; i++) {
            //We cannot pick the entire original word as a single match
            if (start == 0 && i == n) continue; 

            // Extract the prefix view 
            string_view prefix(word.data()+start,i-start);

            if (hash.count(string(prefix))) {
                if (dfs(word, i, hash)) {
                    return cache[start] = 1; // Mark as true
                }
            }
        }

        return cache[start] = 0; // Mark as false
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> hash(words.begin(), words.end());
        vector<string> Ans;

        for (const string& word : words) {
            if (word.empty()) continue;
            
            // Reset the cache for the current word's length
            cache.assign(word.size(), -1); 
            
            if (dfs(word, 0, hash)) {
                Ans.push_back(word);
            }
        }
        return Ans;
    }
};

        //check for each word , whether its concatenated or not
        //store all words in a set. we can check for each word , include or discard , and repeat for each word
        //making a tree like data, with a 2^n time complexity , at last level we will have all concatenated words and check it
        //we can also use another approach , what we can do is for each word , we will try to find out iteratively whether a word exists or not, for like catdogcats , we will check one by one and when we get word cat , we check if its present and remaining word also presents in set. we know its made up by concatenation of two words , it become our answer
        //or in another case where remaining is also a concatenated word , we can check if current word exits in set and for remaining word we will run dfs again and check if its a concatenation of words or not
        //in either situation we will return true if it follows , false otherwise

        //we can use a map as cache to exit recursion early if word already exists in cache 
int main(){
    vector<string> words = {
        "cat",
        "cats",
        "catsdogcats",
        "dog",
        "dogcatsdog",
        "hippopotamuses",
        "rat",
        "ratcatdogcat"
    };
    Solution sol1;
    vector<string> ans = sol1.findAllConcatenatedWordsInADict(words);
    for(auto it : ans)cout<<it<<" ";
    return 0;
}