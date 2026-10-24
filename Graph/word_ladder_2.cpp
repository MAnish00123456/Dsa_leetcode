// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, 
// or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog"

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#include<queue>
#include<algorithm>

//did classic dfs first , didnt worked out for every case because it finds out every path instead of shortest
//optimized , run a bfs first to precompute to find the minimum distance to reach endword if possible , then using this precomputation , run a dfs and instead of going start to endword , we go reverse from endword to stword , only deep down in a path if distance[ngbr] == distanc[word]-1 , this will make sure no unnecessary branches are formed
//use unordered_set instead of pattern wise vector solution i did in word ladder 1 , set is much faster here, instead of patterns manipulate char by char for each indice and see which ngbr is present in list

class Solution {
private:
vector<vector<string>>Ans;
unordered_map<string,int>distance;
// go from endword to beginword
void dfs(string word , string target , vector<string>&path , unordered_set<string>&WordsList){
    path.push_back(word);
    if(word == target){
        vector<string> real = path;
        reverse(real.begin(),real.end());
        Ans.push_back(real);
        path.pop_back();
        return;
    }

    string original = word;
    for(int j = 0 ; j <word.size() ; j++){
        char old_char = word[j];
        for(char c = 'a' ; c <= 'z' ; c++){
            word[j] = c;
            if(WordsList.count(word) && distance[word] == distance[original]-1){
                dfs(word,target,path,WordsList);
            }
        }
        word[j] = old_char; 
    }
    path.pop_back();
}

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
    unordered_set<string>WordsList(begin(wordList),end(wordList));
    if(!WordsList.count(endWord))return {};
    WordsList.insert(beginWord);

    queue<string>q;
    q.push(beginWord);
    distance[beginWord] = 0;
    while(!q.empty()){
        string word = q.front();
        q.pop();

        if(word == endWord)break;

        string original = word;
        for(int i = 0 ;i < word.size() ; i++){
            char old_char = word[i];
            for(char c = 'a' ; c <= 'z' ; c++){
                word[i] = c;
                if(WordsList.count(word)){
                    if(!distance.count(word)){
                        distance[word] = distance[original]+1;
                        q.push(word);
                    }
                }
            }
            word[i] = old_char;
        }
    }

        vector<string>path;
        dfs(endWord,beginWord,path,WordsList);
    return Ans;
    }
};

int main(){
    vector<string>wordList = {"hot","dot","dog","lot","log","cog"};
    Solution sol1;
    vector<vector<string>>ans = sol1.findLadders("hit","cog",wordList);

    for(auto it : ans){
        for(auto j : it)cout<<j<<" -> ";
        cout<<"/0"<<"\n";
    }
    return 0;
}