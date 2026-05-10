//used in 2521

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>


/**
 * Problem:
 * Find the number of DISTINCT prime factors present
 * across all numbers in the array.
 *
 * Example:
 * nums = [2,4,3,7,10]
 *
 * Prime factors:
 * 2  -> {2}
 * 4  -> {2}
 * 3  -> {3}
 * 7  -> {7}
 * 10 -> {2,5}
 *
 * Unique prime factors overall = {2,3,5,7}
 * Answer = 4
 *
 * ----------------------------------------------------
 * Overall Time Complexity:
 * O(maxVal log log maxVal + n log maxVal)
 *
 * maxVal -> largest element in nums
 * n      -> size of nums
 *
 * ----------------------------------------------------
 * Overall Space Complexity:
 * O(maxVal)
 */

class Solution {


    /*
     * Function to precompute Smallest Prime Factor (SPF)
     * for every number from 1 to n.
     *
     * SPF[x] stores the smallest prime factor of x.
     *
     * Example:
     * SPF[12] = 2
     * SPF[15] = 3
     * SPF[49] = 7
     *
     * ----------------------------------------------------
     * Time Complexity:
     * O(n log log n)
     *
     * Space Complexity:
     * O(n)
     */
    std::vector<int> SmallestPrimeFactors(int n) {

        // SPF array of size n+1
        std::vector<int> SPF(n + 1);

        /*
         * Initially assume every number is prime,
         * so SPF[i] = i
         */
        for (int i = 0; i < SPF.size(); i++) {
            SPF[i] = i;
        }

        /*
         * Modified Sieve of Eratosthenes
         *
         * If SPF[j] == j,
         * then 'j' is prime.
         */
        for (int j = 2; j * j < SPF.size(); j++) {

            // Process only prime numbers
            if (SPF[j] == j) {

                /*
                 * Mark smallest prime factor for multiples of j
                 *
                 * Start from j*j because smaller multiples
                 * are already processed.
                 */
                for (int k = j * j; k < SPF.size(); k += j) {

                    /*
                     * Update SPF only once because
                     * first prime factor encountered
                     * is always the smallest.
                     */
                    if (SPF[k] == k) {
                        SPF[k] = j;
                    }
                }
            }
        }

        return SPF;
    }

    /*
     * Function to count distinct prime factors
     * across all numbers in nums.
     *
     * Uses SPF array for fast factorization.
     *
     * ----------------------------------------------------
     * Time Complexity:
     * O(n log maxVal)
     *
     * Why?
     * Each factorization step divides the number,
     * so each number reduces logarithmically.
     *
     * Space Complexity:
     * O(number of distinct prime factors)
     */
    int CountPrimeFactors(std::vector<int>& nums, std::vector<int>& SPF) {

        // Set stores only unique prime factors
        std::set<int> Unique;

        // Traverse every number in array
        for(int val : nums){

            /*
             * Repeatedly divide by smallest prime factor
             * until number becomes 1
             */
            while(val > 1){

                // Fetch smallest prime factor
                int factor = SPF[val];

                // Store unique prime factor
                Unique.insert(factor);

                // Remove that factor from current number
                val /= SPF[val];
            }
        }

        // Return total unique prime factors
        return Unique.size();
    }

public:
    int distinctPrimeFactors(std::vector<int>& nums) {

        /*
         * Find largest element in array
         *
         * SPF only needs to be computed till max value,
         * because factorization never accesses values beyond it.
         */
        int maxVal = *max_element(nums.begin(), nums.end());

        // Precompute SPF array
        std::vector<int> SPF = SmallestPrimeFactors(maxVal);

        // Count distinct prime factors using SPF
        int count = CountPrimeFactors(nums, SPF);

        return count;
    }
};

int main(){
    std::vector<int> nums = {2,4,3,17,12,10,6};
    Solution sol1;
    int UniqueCount = sol1.distinctPrimeFactors(nums);
    std::cout<<UniqueCount;
    return 0;
}