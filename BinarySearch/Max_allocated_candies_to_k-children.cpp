//If every child receives exactly x candies
// how many children can we serve?


//for ex :- candies = [5,8,6] , childrens = 3
//low = 1 and high = 8, lets assume maxAllowedCandies to each child  as 4
//so for 1st pile , we have 5 candies , so with allowed candies only 1 child can get 4 candies out of it , so child =1
//for 2nd pile , we have 8 candies , so with allowed candies , 2 childrens can get max 4 candies each , so child = 3
//from last pile , we have 6 candies  , so with allowed candies, only 1 children can get max 4 candies , so child = 4
//atlast we were able to serve 4 childs with each child getting exactly 4 candies , an its greater than our given childrens , we will store the ans and check for more possible maximum allowed candy


#include<iostream>
#include<algorithm>
#include<vector>

//this function helps to determine if using our given max allowed candies , we are able to allocate candies to k child from pile of candies
bool isValid(std::vector<int>&candies,long long k,int MaxAllowedCandies){
    long long child = 0 ;
    for(int i = 0;i<candies.size();i++){
        child += candies[i] / MaxAllowedCandies;//only check for  the whole amount of candy a child can get
    }
    return child>=k;//if allocation of candies to the childs are more than given child , we will return true
}


    int maximumCandies(std::vector<int>& candies, long long k) {
        int low = 1 ;//min amount of candy a child can get is 1
        int high = *max_element(candies.begin(),candies.end());//the max amount of candy a child can get is the maximum pile of candy available
        int ans = 0;//to store the maximum amount of candy that can be given to a child;
        while(low<=high){
            int mid = low + (high-low)/2;//mid determines our max allowed candy a child can get from a pile of candy at a time
            if(isValid(candies,k,mid)){
                ans = mid;
                low = mid+1;//if using our current max allowed quantity we are able to give candies to k childrens ,we will store the amount and try to find a  more max quantity we can give to a child 
            }
            else{
                high = mid -1 ;//else if using current allowed quantity we are not able to give candy to child , we will search for  lower value
            }
        }
        return ans;
    }








int main(){
    std::vector<int> candies = {5,8,6};
    long long children = 3;
    int MaxAllowedCandies = maximumCandies(candies,children);
    std::cout<<MaxAllowedCandies;
    return 0;
}