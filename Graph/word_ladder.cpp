// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
class Solution {
    public:
        int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
            //we need minimum wirds to reach Endword , can be achieved using bfs
            //each word differs from other word by single char so it acts like a neighbor of word , so first we will find all neighbors for each word we been given , to do it efficiently , we know for each word we tryna replace each char with another to get another word. so we can make a pattern (like regex in python but diff style) we will chnge the char to be removed with a * and then add remaining chars , it kinda forms like a pattern(*od , *it , h*t) like this , then for each word we can determine these patterns and when 2 words have same pattern they are our neighbors
    
            //so build an adjacency list using this trick
    
            //then after adjacency list , we run a normal bfs , starting with beginWord , and traverse the list until we reach our endWord
            //and to add neighbor words in queue , we will use pattern trick and put all unvisited neighbors in queue
    
            std::unordered_map<std::string,std::vector<std::string>>AdjList;
    
            wordList.push_back(beginWord);//it may , may not be in list
            //bidirectional
            for(std::string word : wordList){
                for(int j = 0 ; j < word.size() ; j++){
                    std::string pattern = word.substr(0,j) + "*" + word.substr(j+1,word.size());
                    AdjList[pattern].push_back(word);
                }
            }
    
            std::unordered_set<std::string>visited;
            visited.insert(beginWord);
            std::queue<std::string>q;
            q.push(beginWord);
            int res = 1;
            //BFS
            while(!q.empty()){
                int sz = q.size();
                while(sz--){
                    std::string word = q.front();
                    q.pop();
                    if(word == endWord)return res;
    
                    for(int j = 0 ; j < word.size() ; j++){
                        std::string pattern = word.substr(0,j) + "*" + word.substr(j+1);
                        for(std::string& ngbr : AdjList[pattern]){
                            if(!visited.count(ngbr)){
                                visited.insert(ngbr);
                                q.push(ngbr);
                            }
                        }
                    }
                }
                res++;
            }
    
            return 0;
        }
    };

    int main(){
        std::string beginWord = "hit";
        std::string endWord = "cog";
        std::vector<std::string> wordList = {"hot","dot","dog","lot","log","cog"};
        Solution sol1;
        std::cout<<"Min words to reach endWord : "<<sol1.ladderLength(beginWord,endWord,wordList);
        return 0;
    }