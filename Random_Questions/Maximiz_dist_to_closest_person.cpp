// You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

// There is at least one empty seat, and at least one person sitting.

// Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

// Return that maximum distance to the closest person.

// Input: seats = [1,0,0,0,1,0,1]
// Output: 2
// Explanation: 
// If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
// If Alex sits in any other open seat, the closest person has distance 1.
// Thus, the maximum distance to the closest person is 2.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int maxDistToClosest(vector<int>& seats) {
            //there are 3 cases , for alex to sit
            //if there are leading empty seats , alex should sit at first sit
            //if alex wants to sit btw 2 peeps , he need to sit in middle
            //if there are empty seats at last , he should at last seat , if its distance is maximum thn current
    
            int prev_person = -1;//last person indice
            int max_dist = 0;
            int n = seats.size();
            for(int i = 0 ; i < seats.size() ; i++){
                if(seats[i] == 1){
                    if(prev_person == -1){
                        //case 1 , leading empty seats
                        if(i > max_dist){
                            max_dist =max(max_dist,i);
                        }
                    }else{
                        //case 2 , alex sits in middle
                        int crnt_dist = (i-prev_person)/2;
                        max_dist = max(max_dist,crnt_dist);
                    }
                prev_person = i;
                }
            }
            //case 3 , if there are any empty seats at the end
            if(prev_person != -1 && n-1-prev_person > max_dist){
                max_dist = n-1-prev_person;
            }
    
            return  max_dist;
    
        }
    };

int main(){
    vector<int> seats = {1,0,0,0,1,0,1};

    Solution sol1;

    cout<<sol1.maxDistToClosest(seats);
    return 0;
}
