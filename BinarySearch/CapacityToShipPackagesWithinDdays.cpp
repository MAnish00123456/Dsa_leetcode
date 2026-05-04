//It is similar to our book allocation problem 
//In this question we have been given :- A conveyor belt has packages that must be shipped from one port to another within days days.
// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.


#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

//to validate if using our least allowed weight we are able to ship packages before or on that day
bool isValid(std::vector<int>&weights ,int days , int LeastAllowedWeight){
    int day = 1 , weight = 0;
    for(int i = 0 ;i<weights.size();i++){
        if(weights[i] > LeastAllowedWeight){
            return false;
        }
        if(weight + weights[i] <= LeastAllowedWeight){
            weight+=weights[i];
        }
        else{
            day++;
            weight = weights[i];
        }
    }
    return day<=days;
}

int shipWithinDays(std::vector<int>&weights,int days){
    int low = *max_element(weights.begin(),weights.end());//our lowest possible weight should be atleast equal to our maximum weight in the array in order to ship that package
    int high = std::accumulate(weights.begin(),weights.end(),0);//our highest possible weight that should be allowed is the total sum of weights of given array
    int ans = -1;//to store the least possible weight to ship packages
    while(low <= high){
        int mid = low + (high-low)/2;//guessing the least possible weight that is allowed for shipping packages on d days
        if(isValid(weights,days,mid)){
            ans = mid ;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
return ans;
}

int main(){
    std::vector<int>weights={1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    int least_weight_capacity = shipWithinDays(weights,days);
    std::cout<<least_weight_capacity<<std::endl;
    return 0;
}
