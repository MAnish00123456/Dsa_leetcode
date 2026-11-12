// You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

// Return the minimum number of CPU intervals required to complete all tasks.

// Input: tasks = ["A","A","A","B","B","B"], n = 2

// Output: 8

// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

// After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//we  will first process tasks with higher freq so that our interval time is minimum , to get to know about higher freq task at each interval, we will use a max heap to store this info.
//simultaneously , we will maintain a queue in which we will store tasks with time period , this time period depicts the time at which this task should be processed again

//repeatedly do it until all tasks are scheduled
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freqArr(26,0);
        priority_queue<int>pq;
        for(char ch : tasks)freqArr[ch-'A']++;
        for(int val : freqArr){
            if(val > 0)pq.push(val);
        }

        queue<pair<int,int>>q;//freq of task , time at which it will enter in heap

        int time = 0;
        while(!pq.empty() || !q.empty()){
            time++;
           if(!pq.empty()){
           int freq = pq.top() - 1;//remaining freq of the current task , if it is non zero , we need to process this task again after some period , this info is stored in queue
            pq.pop();
            if(freq > 0)q.push({freq,time+n});
           } 
            //add the task again in heap , when its waiting period is finished
            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};


int main(){
    vector<char>tasks = {'A','A','A','B','B','B'};
    int n =2;
    Solution sol1;

    cout<<sol1.leastInterval(tasks,n);
    return 0;
}
