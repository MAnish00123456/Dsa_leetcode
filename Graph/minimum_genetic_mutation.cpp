// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

// Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

// For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
// There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

// Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

// Note that the starting point is assumed to be valid, so it might not be included in the bank.

// Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
// Output: 2

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

class Solution {
    public:
        int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank) {
            //kinda similar to word ladder(127) , need minimum steps to reach to endGene starting with startGene
    
            //build adjacency list using pattern trick , like in question 127 we did
    
            std::unordered_map<std::string,std::vector<std::string>>AdjList;
            bank.push_back(startGene);//this may or may not be included in bank
    
            for(std::string& gene : bank){
                for(int j = 0 ; j < gene.size() ; j++){
                    std::string pattern = gene.substr(0,j) + "*" + gene.substr(j+1);
                    AdjList[pattern].push_back(gene);
                }
            }
    
            std::unordered_set<std::string>visited;
            std::queue<std::string>q;
    
            visited.insert(startGene);
            q.push(startGene);
            int res = 0;
    
            while(!q.empty()){
                int sz = q.size();
                while(sz--){
                    std::string gene = q.front();
                 q.pop();
                 if(gene == endGene)return res;
                 for(int j = 0 ; j < gene.size() ; j++){
                    std::string pattern = gene.substr(0,j) + "*" + gene.substr(j+1);
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
            return -1;
        }
    };

    int main(){
        std::string startGene = "AACCGGTT";
        std::string endGene = "AAACGGTA";
        std::vector<std::string>bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
        Solution sol1;
        std::cout<<"Minimum number of mutation : "<<sol1.minMutation(startGene,endGene,bank);
        return 0;
    }