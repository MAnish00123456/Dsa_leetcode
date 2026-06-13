// There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. You are given an array heights of distinct integers where heights[i] represents the height of the ith person.
// A person can see another person to their right in the queue if everybody in between is shorter than both of them. More formally, the ith person can see the jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).
// Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.

// Input: heights = [10,6,8,5,11,9]
// Output: [3,1,2,1,1,0]
// Explanation:
// Person 0 can see person 1, 2, and 4.
// Person 1 can see person 2.
// Person 2 can see person 3 and 4.
// Person 3 can see person 4.
// Person 4 can see person 5.
// Person 5 can see no one since nobody is to the right of them.

//a type of monotonic decreasing problem where we need to find next greater height to the right side
#include<iostream>
#include<vector>
#include<stack>

class Solution {
    public:
        std::vector<int> canSeePersonsCount(std::vector<int>& heights) {
            int visiblePeople;//count number of persons a person can see to right side
            std::stack<int>st;//monotonic decreasing stack to store next greater height because past that  the person cant see anymore persons
            std::vector<int>Ans(heights.size());
            int n = heights.size() - 1;
            for(int i = n ; i >= 0 ; i--){
                visiblePeople = 0;
                while(!st.empty() && st.top() <= heights[i]){
                  //case 1 : when curr person has height more than height in top of stack , it means curr person can see this person so increase count
                    visiblePeople++;
                    st.pop();
                }
                //case 2 : when we encounter a person with a greater height , means past that person we cant see anymore person but we can see this person tho , so increment visiblePeople
                if(!st.empty()){
                    visiblePeople++;
                }
                //case 3 : would be when stack is empty (in case of lastmost person visible count will be 0)
                Ans[i]=visiblePeople;
                st.push(heights[i]);
            }
            return Ans;
        }
    };

    int main(){
        std::vector<int>heights = {10,6,8,5,11,9};
        Solution sol1;
        std::vector<int> Ans = sol1.canSeePersonsCount(heights);
        for(int val : Ans){
            std::cout<<val<<" ";
        }
        return 0;
    }