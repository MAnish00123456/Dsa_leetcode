// You are given a 0-indexed array of positive integers tasks, representing tasks that need to be completed in order, where tasks[i] represents the type of the ith task.

// You are also given a positive integer space, which represents the minimum number of days that must pass after the completion of a task before another task of the same type can be performed.

// Each day, until all tasks have been completed, you must either:

// Complete the next task from tasks, or
// Take a break.
// Return the minimum number of days needed to complete all tasks.

// Input: tasks = [1,2,1,2,3,1], space = 3
// Output: 9
// Explanation:
// One way to complete all tasks in 9 days is as follows:
// Day 1: Complete the 0th task.
// Day 2: Complete the 1st task.
// Day 3: Take a break.
// Day 4: Take a break.
// Day 5: Complete the 2nd task.
// Day 6: Complete the 3rd task.
// Day 7: Take a break.
// Day 8: Complete the 4th task.
// Day 9: Complete the 5th task.
// It can be shown that the tasks cannot be completed in less than 9 days.

#include<iostream>
#include<vector>
using namespace std;
#include<unordered_map>


class Solution {
    using ll = long long;
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        //store last day of completing a task and use it to take breaks in between
        unordered_map<ll,ll>hash;//task,last day
         ll last_day = 0;

        for(int i = 0 ; i < tasks.size() ; i++){
            if(hash.count(tasks[i])){
                //check if we have reached enough days(more than given space) ahead from last scheduling day , and can process task again or we need a break and then continue from next day
                last_day = max(last_day,hash[tasks[i]]+space) + 1;//+1 depicts new day of performing task again
                hash[tasks[i]] = last_day;
            }else{
                last_day++;
                hash[tasks[i]] = last_day;
            }
        }
        return last_day;

    }
};

int main(){
    vector<int>tasks = {1,2,1,2,3,1};
    int space = 3;

    Solution sol1;

    cout<<sol1.taskSchedulerII(tasks,space);
    return 0;
}