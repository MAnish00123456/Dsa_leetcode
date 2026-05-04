//You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.
// Each bus can make multiple trips successively; that is, the next trip can start immediately after completing
// the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.
// You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for 
// all buses to complete at least totalTrips trips.

#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long

// Checks whether all buses together can complete at least totalTrips
// within the given allowed time
    bool isValid(std::vector<int>&time , int totalTrips , ll minAllowedTime){
        ll trips = 0;
        for(int i = 0 ; i < time.size() ; i++){
            trips += (minAllowedTime/time[i]);
            if(trips >= totalTrips) return true;
        }
        return trips < totalTrips?false:true;
    }

    long long minimumTime(std::vector<int>& time, int totalTrips) {
        ll low = 1;
        // Maximum possible answer:
        // even if only the fastest bus does all trips
        ll high = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;;
        ll minTime = high;
        while(low <= high){
            ll mid = low + (high-low)/2;
            if(isValid(time,totalTrips,mid)){
                minTime =std::min(minTime,mid);
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return minTime;
    }