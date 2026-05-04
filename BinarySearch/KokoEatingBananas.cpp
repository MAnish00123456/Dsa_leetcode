//In this question , we have been given a piles of bananas where ith pile represent number of bananas on that pile . we have a guard who has gone on break for h hours, now koko have h hours to finish all the bananas
//of the piles , we have to find a min banana eating speed means number of bananas to eat per hour to finish all the piles of bananas.
//the min bananas koko can eat in one hour is less to less 1 nd max is the maximum number of bananas in the piles

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

//For ex => piles = [3,6,7,11] , h = 8 , st= 1 , end = 11
//for 1st iteration our minEating speed would be 7(mid)
//now isValid(7) => total_time = 0 rn
//koko went to 1st pile having 3 bananas , with given speed he is able to finish all bananas in 1 hour , total_time = 1
//koko went to 2nd pile having 6 bananas , with given speed he is able to finish all bananas in 1 hour , total_time = 2
//koko went to 3rd pile having 7 bananas , with given speed he is able to finish all bananas in 1 hour , total_time = 3
//koko wen to 4rth pile having 11 bananas , with given speed he will first eat 7 bananas in 1 hour and other 4 bananas in next 1 hour , so total_time = 5 which is less than 8(h , guard gone away) , so this 
//can be min speed but we will now try to find more min speed koko can achieve and will repeat same process

//to check if koko is able to eat all bananas using minEatingspeed
bool isValid(std::vector<int>&piles, int minSpeed , int h){
int total_time = 0 ;//to store total time required to eat all bananas
for(int i = 0;i<piles.size();i++){
    //this code logic helps us to find ceiling value of time to finsih all bananas
    total_time+=piles[i]/minSpeed;
    if(piles[i]%minSpeed != 0){
        total_time++;
    }
}
return total_time>h?false:true;
}


int minEatingSpeed(std::vector<int>&piles,int h){
int st = 1;
int end = *max_element(piles.begin(),piles.end());
int ans = 0;

while(st<=end){
    int mid = st + (end-st)/2;
    //mid here acts as minimum eating speed of bananas per hour ,  koko can achieve to eat all bananas in piles before guard come back

    if(isValid(piles,mid,h)){
        //if using mid as min eating speed , we are able to finish all bananas on time then we will store this answer and try to find a more minimum speed koko can acieve to finish all bananas
        ans = mid;
            end = mid -1;
    }
    //if koko is not able to finsih all bananas by using mid as minEatingSpeed , then we need a little bigger time than this
    else{
        st = mid + 1;
    }
}
return ans;
}

int main(){
    std::vector<int>  piles = {3,6,7,11};
    int h = 8;
    int minEatingspeed = minEatingSpeed(piles,h);
    std::cout<<minEatingspeed;
    return 0;
}