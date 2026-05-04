//Aggressive cows problem
//we have giveen an array 'Stall' where each ith value provides the position of stall
// We have given an integer 'K' which denotes the number of aggressive cows . 
//Our task is to assign stalls to the given cows such that minimum distance btw any 2 of them is largest possible distace that can be calculated.
//Given that there will be atleast 2 cows for this problem.
//the lowest distance that can be btw any 2 cows would be minimum distace btw any 2 cows stall positon and the maximum distace btw any 2 would be largest minimum distace btw them that is the highest value in array - the lowest value in the array

#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>
bool isValid(std::vector<int>& StallPos,int NoOfCows , int minAllowedDistance){
    int Cows=1; int LastStallPos=StallPos[0];
    for(int i=1;i<StallPos.size();i++){
        if(StallPos[i]-LastStallPos>=minAllowedDistance){
            Cows++;
            LastStallPos=StallPos[i];
        }
        if(Cows>=NoOfCows) {return true;}
    }
    return false;
}
int LargestMinPossibleDistance(std::vector<int>& StallPos , int NoOfCows){
    std::sort(StallPos.begin(),StallPos.end());
    int min=*min_element(StallPos.begin(),StallPos.end());
    int max=*max_element(StallPos.begin(),StallPos.end());

    int st=1;//least Minimum distace btw any 2 cows
    int end=max-min;//Maximum possible distace btw any 2 cows
    int ans=-1;
    while(st<=end){
        int mid=st+ (end-st)/2;
    if(isValid(StallPos,NoOfCows,mid)){
        ans=mid;
        st=mid+1;
    }
    else{
        end=mid-1;
    }
    }
    return ans;

}


// int main(){
//     std::vector<int> StallPos={1,2,8,4,9};
//     int NoOfCows=3;
//     int LargestMinDistance=LargestMinPossibleDistance(StallPos,NoOfCows);
//     std::cout<<"Largest minimum possible distance btw any 2 cows such that every cow is assigned a stall : "<<LargestMinDistance;
//     return 0;
// }

//Automated test cases code
bool bruteCheck(std::vector<int>& stalls, int cows, int dist) {
    int placed = 1;
    int last = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= dist) {
            placed++;
            last = stalls[i];
        }
    }
    return placed >= cows;
}

int bruteForce(std::vector<int> stalls, int cows) {
    sort(stalls.begin(), stalls.end());

    int maxDist = stalls.back() - stalls.front();
    int ans = -1;

    for (int d = 1; d <= maxDist; d++) {
        if (bruteCheck(stalls, cows, d))
            ans = d;
    }
    return ans;
}

/* ================= TEST RUNNER ================= */

void runTest(std::vector<int> stalls, int cows, int testNo) {
    int fast = LargestMinPossibleDistance(stalls, cows);
    int slow = bruteForce(stalls, cows);

    if (fast != slow) {
        std::cout << "❌ Test Failed (Test #" << testNo << ")\n";
        std::cout << "Stalls: ";
        for (int x : stalls) std::cout << x << " ";
        std::cout << "\nCows: " << cows << std::endl;
        std::cout << "Your Answer: " << fast << std::endl;
        std::cout << "Correct: " << slow << std::endl;
        exit(0);
    }
}

/* ================= MAIN ================= */

int main() {
    srand(time(0));
    int testNo = 1;

    /* ---------- EDGE CASES ---------- */

    runTest({1, 2}, 2, testNo++);                  // minimum case
    runTest({1, 2, 3, 4, 5}, 5, testNo++);         // cows == stalls
    runTest({1, 2, 3, 4, 5}, 2, testNo++);         // farthest ends
    runTest({10, 20, 30, 40}, 1, testNo++);        // single cow
    runTest({5, 5, 5, 5}, 2, testNo++);            // duplicate stalls
    runTest({1, 1000}, 2, testNo++);               // very far apart
    runTest({1, 2, 8, 4, 9}, 3, testNo++);         // classic example
    runTest({1, 2, 4, 8, 9}, 3, testNo++);         // sorted version
    runTest({1, 100, 101, 102}, 3, testNo++);
    runTest({1, 2, 3, 1000000}, 2, testNo++);

    /* ---------- RANDOM TESTS ---------- */

    const int RANDOM_TESTS = 200;

    for (int i = 0; i < RANDOM_TESTS; i++) {
        int n = rand() % 10 + 2;              // stalls: 2–11
        int cows = rand() % n + 1;            // cows: 1–n

        std::vector<int> stalls(n);
        for (int j = 0; j < n; j++) {
            stalls[j] = rand() % 100 + 1;     // positions: 1–100
        }

        runTest(stalls, cows, testNo++);
    }

    std::cout << "✅ All tests passed (" << testNo - 1 << " cases)!\n";
    return 0;
}
