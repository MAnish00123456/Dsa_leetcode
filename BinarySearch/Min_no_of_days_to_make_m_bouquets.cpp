// Binary Search on Answer
// We search the minimum day such that we can form m bouquets.
// Each bouquet needs k adjacent flowers that have bloomed by that day.
// isValid() checks if it's possible to form m bouquets by a given day.

#include <iostream>
#include <vector>
#include<algorithm>

bool isValid(std::vector<int> &bloomDay, int adjacent_flower_count,
             int number_of_bouquets, int MinAllowedBloomingDay)
{
    int total_bouquet_count =
        0; // storing all the bouquets we can make using adjacent flowers
           // which already bloomed on or before MinAllowedBloomingDay
    for (int i = 0; i < bloomDay.size(); i++)
    {
        int total_adjacent_flower_count =
            0; // storing adjacent flower counts iteratively upto our
               // allowed adjacent flower counts that are already bloomed
               // and will be use to make bouquets

        // collect adjacent flowers that have bloomed by the given day
        while (i < bloomDay.size() &&
               total_adjacent_flower_count < adjacent_flower_count &&
               bloomDay[i] <= MinAllowedBloomingDay)
        {
            total_adjacent_flower_count++;
            i++;
        }
        // if our adjacent flower count that are already bloomed in given
        // days become equal to our given adjacent flower count , we can
        // make a bouquet
        if (total_adjacent_flower_count == adjacent_flower_count)
        {
            total_bouquet_count++;
            i--; // step back because the for loop will increment i again
        }
        // if at any point of iteration , we are able to make m bouquets or
        // more , we will return true from that point
        if (total_bouquet_count >= number_of_bouquets)
        {
            return true;
        }
    }
    return false;
}

int minDays(std::vector<int> &bloomDay, int m, int k)
{
    // if our flower count is less than our k*m we are unable to make
    // bouquets
    if (((long long)k * m) > bloomDay.size())
        return -1;
    int low = 1; // Min number of days a flower would need to bloom has to
                 // be atleast 1 day
    int high = *max_element(
        bloomDay.begin(),
        bloomDay
            .end()); // max number of days a flower would need to bloom will
                     // be the maximum number of days we have in our array
    int Ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) /
                            2; // mid here act as our Min number of blooming
                               // days a flower would have to bloom
        if (isValid(bloomDay, k, m, mid))
        {
            Ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return Ans;
}


int main(){
    std::vector<int>bloomingDay ={7,7,7,7,12,7,7};
    int k = 3;
    int m  = 2;
    int minDaysToMakemBouquets = minDays(bloomingDay , m , k);
    std::cout<<"Min days to make "<<m<<" bouquets using "<<k<<" adjacent flowers : "<<minDaysToMakemBouquets<<std::endl;
    return 0; 

}