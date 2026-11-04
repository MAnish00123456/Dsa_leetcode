// You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

// The lock initially starts at '0000', a string representing the state of the 4 wheels.

// You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

// Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

// Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
// Output: 6
// Explanation: 
// A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
// Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
// because the wheels of the lock become stuck after the display becomes the dead end "0102".

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>

//we know for lock "0000" , for each digit we can either add + 1 or subtract -1 from it for new digit , and given 4 digits in lock so total new 8 combinations for a lock
//we will find all these 8 combinations and push inside queue and track our target lock
//9 + 1 should be 0 so we do (9+1)%10 when adding 1
//0-1 should be 9 so we do (0-1+10)%10 when subtracting 1

std::vector<std::string>Childrens(std::string lock){
    std::vector<std::string>childs;
    std::string dig;
    for(int i = 0 ; i < lock.size() ; i++){
         dig = std::to_string(((lock[i]-'0')+1)%10);
        childs.push_back(lock.substr(0,i) + dig + lock.substr(i+1));
         dig = std::to_string(((lock[i]-'0')-1+10)%10);
        childs.push_back(lock.substr(0,i) + dig + lock.substr(i+1));
    }
    return childs;
}
class Solution {
public:
    int openLock(std::vector<std::string>& deadends, std::string target) {
        //as we know we dont want to visit deadends , so we will just mark them as visited , hence this way we will never reach these ends
        std::unordered_set<std::string>visited(deadends.begin(),deadends.end());
        //if our starting point is our deadend , we cant move further
        if(visited.count("0000"))return -1;
        std::queue<std::pair<std::string,int>>q;
        q.push({"0000",0});

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto[lock,turns] = q.front();
                q.pop();
                if(lock == target)return turns;
                //find all 8 combinations for this lock pattern
                std::vector<std::string>childrens = Childrens(lock);
                for(std::string combination : childrens){
                    if(!visited.count(combination)){
                        visited.insert(combination);
                        q.push({combination,turns+1});
                    }
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution sol1;
    std::vector<std::string>deadend = {"0201","0101","0102","1212","2002"};
    std::string target = "0202";

    std::cout<<"No of turns = "<<sol1.openLock(deadend,target);
    return 0;
}