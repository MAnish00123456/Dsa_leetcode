// You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.

// The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.

// Return the maximum number of matchings between players and trainers that satisfy these conditions.

// Input: players = [4,7,9], trainers = [8,2,5,8]
// Output: 2
// Explanation:
// One of the ways we can form two matchings is as follows:
// - players[0] can be matched with trainers[0] since 4 <= 8.
// - players[1] can be matched with trainers[3] since 7 <= 8.
// It can be proven that 2 is the maximum number of matchings that can be formed.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
        int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
            sort(begin(players),end(players),[](int a , int b){
                return  a>b;
            });
            sort(begin(trainers),end(trainers),[](int a , int b){
                return a>b;
            });   
    
            int j = 0;
            int ans = 0;
            int sz = trainers.size();
            for(int i = 0 ; i < players.size(); i++){
                if(j<sz &&  trainers[j] >= players[i]){
                    ans++;
                    j++;
                }
            }
            return ans;
        }
    };

int main(){
    vector<int>players = {4,7,9};
    vector<int>trainers = {8,2,5,8};
    Solution sol1;
    cout<<sol1.matchPlayersAndTrainers(players,trainers);
    return 0;
    
}