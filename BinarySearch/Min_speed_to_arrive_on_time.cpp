//in this question :-> You are given a floating-point number hour, representing the amount of time you have to reach the office. 
//To commute to the office, you must take n trains in sequential order. You are also given an integer array dist of length n, where dist[i] 
//describes the distance (in kilometers) of the ith train ride.

// Each train can only depart at an integer hour, so you may need to wait in between each train ride.
// For example, if the 1st train ride takes 1.5 hours, you must wait for an additional 0.5 hours before you can depart on the 2nd train ride at the 2 hour mark.

//Every train must start from an integer hour before departing to other train , for ex -> if 1st train takes 0.5 hour to reach destination , the person should wait additional 0.5 hour to depart using other train , this thing appplies to every train except last train , because we dont have any train to depart after that , so we can use the time as it is

//so what we do is calculate time taken by using formulae distance / speed for each train ride , and if its not the last train , we will take ceiling value of it.

//because of integer departure constraint , total time would be = summation from i=0 to n-2 (ceiling(dist[i]/speed)) + dist[n-1]/speed

#include<iostream>
#include<vector>
#include<cmath>



//this function helps us to find the minimum positive speed with which we can reach to office in given hours
bool isValid(std::vector<int>&dist , double hour , int MinAllowedSpeed){
    double h = 0.0;//to store time taken by each train to complete the ride for given distance
    double Time = 0.0;//to store the total time taken by person to reach to office
    for (int i = 0;i<dist.size();i++){
        h = (double)dist[i]/MinAllowedSpeed;
        if(i != dist.size()-1){
            Time += ceil(h);
        }
        else{
            Time += h;
        }
    }
    return Time<=hour;
}
    int minSpeedOnTime(std::vector<int>& dist, double hour) {
     int low = 1 ;//the minimum speed a train can achieve is 1 km/hr
     int high = 1e7;//the maximum speed a train can achieve , as to cover that particular distance we would require that much speed to finsih journey with less time
     int ans = -1;
     while(low<=high){
        int mid = low + (high-low)/2;//mid acts as our minimum allowed speed a train can achieve to finish the given distance 
        if(isValid(dist,hour,mid)){
            //storing the current speed if we were able to reach on time , and check for more less speed we can attain to finish the distance
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
     }   
     return ans;
    }

    int main(){
        std::vector<int> dist = {1,3,2};
        int hour = 6;
        int Min_speed_ofTrain_to_reach_on_time = minSpeedOnTime(dist , hour);
        std::cout<<Min_speed_ofTrain_to_reach_on_time<<std::endl;
        return 0;
    }