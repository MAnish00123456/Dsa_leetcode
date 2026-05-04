//Painter partiton problem
//Similar concept as Book Allocation problem
//we have given an array 'A' in which at each ith index we have given the length  of a painting board and for 1 unit length of booard it 
// take exactly 1 unit of time to paint the baord. We have given 'M' painting  boards and 'N' painters.
//We have to allocate boatds to painters such that the time taken by a painter from all valid assignments to paint the board is minimum.
// Boards are assigned in the contiguous order .
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include <numeric>
#include <cstdlib>
#include <ctime>
bool isValid(std::vector<int>& BoardLength, int BoardCount , int PainterCount , int maximumAllowedTime){
int painters=1;
int length=0;
for(int i=0;i<BoardCount;i++){
    if(BoardLength[i]>maximumAllowedTime) return false;
    if(length+BoardLength[i]<=maximumAllowedTime){
        length+=BoardLength[i];
    }
    else{
        painters++;
        length=BoardLength[i];
    }
}
return painters>PainterCount?false:true;
}


int MinimumTimeToPaintBoards(std::vector<int>& BoardLength, int Boards, int painterCount){
if(painterCount>Boards) return -1;
if(painterCount==0) return -1;
if(Boards==1) return BoardLength[0];
int st= *max_element(BoardLength.begin(),BoardLength.end());
int end=0;
for(int i=0;i<Boards;i++){
    end+=BoardLength[i];
}
int ans=-1;
while(st<=end){
    int mid=st + (end-st)/2;
    if(isValid(BoardLength, Boards, painterCount , mid)){
        ans=mid;
        end=mid-1;
    }
    else{
        st=mid+1;
    }
}
return ans;
}


// int main(){
//     std::vector<int> BoardLength={40,30,10,20};
//     int Boards=BoardLength.size();
//     int painterCount=2;
//     int MinTimeToPaint=MinimumTimeToPaintBoards(BoardLength,Boards,painterCount);
//     std::cout<<"Minimum time to paint all boards : "<<MinTimeToPaint;
//     return 0;
// }

//for automatic test cases generation
bool bruteCheck(std::vector<int>& boards, int painters, int limit) {
    int cnt = 1, sum = 0;
    for (int b : boards) {
        if (sum + b > limit) {
            cnt++;
            sum = b;
        } else {
            sum += b;
        }
    }
    return cnt <= painters;
}

int bruteForce(std::vector<int>& boards, int painters) {
    if (painters > boards.size()) return -1;

    int mx = *max_element(boards.begin(), boards.end());
    int sum = accumulate(boards.begin(), boards.end(), 0);

    for (int t = mx; t <= sum; t++) {
        if (bruteCheck(boards, painters, t))
            return t;
    }
    return -1;
}

/* ================= TEST RUNNER ================= */

void runTest(std::vector<int> boards, int painters, int testNo) {
    int fast = MinimumTimeToPaintBoards(boards, boards.size(), painters);
    int slow = bruteForce(boards, painters);

    if (fast != slow) {
        std::cout << "❌ Test Failed (Test #" << testNo << ")\n";
        std::cout << "Boards: ";
        for (int b : boards) std::cout << b << " ";
        std::cout << "\nPainters: " << painters << std::endl;
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

    runTest({10}, 1, testNo++);                    // single board
    runTest({10, 20, 30}, 1, testNo++);            // single painter
    runTest({5, 5, 5, 5}, 4, testNo++);            // painters == boards
    runTest({5, 10}, 5, testNo++);                 // painters > boards
    runTest({7, 7, 7, 7, 7}, 2, testNo++);         // same lengths
    runTest({1, 1000, 1}, 2, testNo++);            // one large board
    runTest({10, 20, 30, 40}, 2, testNo++);        // increasing
    runTest({40, 30, 20, 10}, 2, testNo++);        // decreasing
    runTest({100, 200, 300, 400, 500}, 3, testNo++);
    runTest({1, 1, 1, 1, 1, 1}, 3, testNo++);

    /* ---------- RANDOM TESTS ---------- */

    const int RANDOM_TESTS = 200;

    for (int i = 0; i < RANDOM_TESTS; i++) {
        int n = rand() % 10 + 1;               // boards: 1–10
        int painters = rand() % (n + 3);       // allow painters > boards

        std::vector<int> boards(n);
        for (int j = 0; j < n; j++) {
            boards[j] = rand() % 100 + 1;      // length: 1–100
        }

        runTest(boards, painters, testNo++);
    }

    std::cout << "✅ All tests passed (" << testNo - 1 << " cases)!\n";
    return 0;
}
