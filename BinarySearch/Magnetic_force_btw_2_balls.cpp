// This is similar to our Aggressive cows problem , as in both we need to find
// minimum maximum distance to place items (whether a cow or a ball)


// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], 
// Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.
// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
// Given the integer array position and the integer m. Return the required force.


// so to better understand this problem , solve aggressive cows first


#include<iostream>
#include<vector>
#include<algorithm>


    bool isValid(std::vector<int>& position, int m, int mid) {
        int lastPos = position[0]; // last position of new ball placed
        int balls = 1;             // count no of balls placed
        for (int i = 0; i < position.size(); i++) {
            // if current position - lastballpos is either greater or equal to
            // our minAllowed max distance(mid) , we will place another ball and
            // update our last ball placed position , as to maximize a minimum
            // magnetic force btw 2 balls we need to place them atleast mid
            // position away
            if (position[i] - lastPos >= mid) {
                balls++;
                lastPos = position[i];
            }
            if (balls >= m) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(std::vector<int>& position, int m) {
        if (m > position.size()) {
            return -1;
        }
        std::sort(position.begin(),
             position.end()); // to find the minimum max distance greedily from
                              // left to right , we need to sort the array
        int low = 1; // the minimum distance btw any 2 balls will be atleast 1
        int high = position.back() -
                   position.front(); // the maximum distance btw any two balls
                                     // is the difference of the maximum and
                                     // minimum valuye of the array
        int Ans = 0;
        while (low <= high) {
            int mid =
                low + (high - low) /
                          2; // mid here act as our candidate minimum Allowed
                             // distance that has to be btw 2 balls so as the
                             // magnetic force btw them is maximum , based on
                             // condtions we will shift distances
            if (isValid(position, m, mid)) {
                Ans = mid;
                low = mid + 1;
                // if we can place m balls with at least 'mid' distance,
                // store it and try to find a larger minimum distance
            } else {
                high = mid - 1;
            }
        }
        return Ans;
    }


    int main(){
        // std::vector<int>position = {5,4,3,2,1,1000000000};
        std::vector<int>position = {1,2,3,4,7};
            int m = 3;
        int minMaxdistance = maxDistance(position , m);
        std::cout<<"the minimum  distance btw "<<m<<" balls as to maximize the magnetic force btw them is : "<<minMaxdistance;
        return 0;
    }