// You are given a 0-indexed integer array nums of length n.

// A split at an index i where 0 <= i <= n - 2 is called valid if the product of the first i + 1 elements and the product of the remaining elements are coprime.

// For example, if nums = [2, 3, 3], then a split at the index i = 0 is valid because 2 and 9 are coprime, while a split at the index i = 1 is not valid because 6 and 3 are not coprime. A split at the index i = 2 is not valid because i == n - 1.
// Return the smallest index i at which the array can be split validly or -1 if there is no such split.

// Two values val1 and val2 are coprime if gcd(val1, val2) == 1 where gcd(val1, val2) is the greatest common divisor of val1 and val2.

//ans at last idx will be -1

// Input: nums = [4,7,8,15,3,5]
// Output: 2

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

class Solution {
    std::unordered_map<int, int> Last_Pos_Of_primeNum(std::vector<int>& nums,
                                                 std::vector<int>& Spf) {
                                                    //store each distinct prime num last position of occurence in given array
        std::unordered_map<int, int> Hashmap;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            while (num > 1) {
                int pf = Spf[num];
                Hashmap[pf] = i;

                while (num % pf == 0) {
                    num /= Spf[num];
                }
            }
        }
        return Hashmap;
    }
//  Idea:
//         A split is invalid if some prime factor appears on both sides.

//         We greedily maintain the farthest index 'ans' that must belong
//         to the left side because of shared prime factors.

//         For every prime:
//         - first time seen -> store its first index
//         - seen again while its first occurrence is inside current left segment
//           -> we must extend the segment to current index

//         Similar to interval merging / partition labels.
public:
    int findValidSplit(std::vector<int>& nums) {
        //precompute smallest prime factors for each num,(modified sieve of eratosthenes) , O(M*log(logM)), M = largest number in array
        auto SPF = [&](int n) {
            std::vector<int> SPF(n + 1);
            for (int i = 0; i < SPF.size(); i++)
                SPF[i] = i;
            for (int i = 2; i * i < SPF.size(); i++) {
                if (SPF[i] == i) {
                    for (int j = i * i; j < SPF.size(); j += i) {
                        if (SPF[j] == j) {
                            SPF[j] = i;
                        }
                    }
                }
            }
            return SPF;
        };

        int maxElem = *max_element(nums.begin(), nums.end());//our M
        std::vector<int> Spf = SPF(maxElem);
        std::unordered_map<int, int> Lastpos = Last_Pos_Of_primeNum(nums, Spf);

        int maxReach = 0; // determines how many indices we need to jump to have
                          // unique prime factors onboth sides of that index.
        for (int i = 0; i < nums.size() - 1; i++) {
            int num = nums[i];
            while (num > 1) {
                int pf = Spf[num];
                maxReach = std::max(maxReach, Lastpos[pf]);
                while (num % pf == 0) {
                    num /= pf;
                }
            }
            if (maxReach == i) {
                return i;
            }
        }
        return -1;
    }
};

int main(){
    std::vector<int> nums = {557663,280817,472963,156253,273349,884803,756869,763183,557663,964357,821411,887849,891133,453379,464279,574373,852749,15031,156253,360169,526159,410203,6101,954851,860599,802573,971693,279173,134243,187367,896953,665011,277747,439441,225683,555143,496303,290317,652033,713311,230107,770047,308323,319607,772907,627217,119311,922463,119311,641131,922463,404773,728417,948281,612373,857707,990589,12739,9127,857963,53113,956003,363397,768613,47981,466027,981569,41597,87149,55021,600883,111953,119083,471871,125641,922463,562577,269069,806999,981073,857707,831587,149351,996461,432457,10903,921091,119083,72671,843289,567323,317003,802129,612373};
    Solution sol1;
    int split = sol1.findValidSplit(nums);
    std::cout<<split;
    return 0;
}