//used in question 2507

#include<iostream>
#include<vector>

/**
 * Problem Idea:
 *
 * We repeatedly replace a number with the sum of its prime factors.
 *
 * Example:
 * 15 = 3 × 5
 * Sum of prime factors = 3 + 5 = 8
 *
 * 8 = 2 × 2 × 2
 * Sum = 2 + 2 + 2 = 6
 *
 * 6 = 2 × 3
 * Sum = 5
 *
 * 5 is prime
 * Sum of prime factors = 5 itself
 *
 * Therefore answer = 5
 */

class Solution {

    /*
     * Function to compute Smallest Prime Factor (SPF)
     * for every number from 1 to n.
     *
     * SPF[x] stores the smallest prime that divides x.
     *
     * Example:
     * SPF[12] = 2
     * SPF[15] = 3
     * SPF[49] = 7
     */
   std::vector<int> SmallestPrimeFactors(int n){

        // Initialize SPF array
       std::vector<int> SPF(n + 1);

        /*
         * Initially assume every number is prime,
         * so SPF[i] = i
         */
        for(int i = 2; i < SPF.size(); i++){
            SPF[i] = i;
        }

        /*
         * Modified Sieve of Eratosthenes
         *
         * If SPF[i] == i,
         * then 'i' is still prime.
         */
        for(int i = 2; i * i < SPF.size(); i++){

            if(SPF[i] == i){

                /*
                 * Mark smallest prime factor for multiples of i
                 *
                 * Start from i*i because smaller multiples
                 * were already processed earlier.
                 */
                for(int j = i * i; j < SPF.size(); j += i){

                    /*
                     * Update only if number is not marked yet
                     * (first prime factor encountered is always smallest)
                     */
                    if(SPF[j] == j){
                        SPF[j] = i;
                    }
                }
            }
        }

        return SPF;
    }

    /*
     * Function to compute sum of prime factors using SPF array
     *
     * Example:
     * n = 12
     *
     * SPF[12] = 2
     * 12 / 2 = 6
     *
     * SPF[6] = 2
     * 6 / 2 = 3
     *
     * SPF[3] = 3
     * 3 / 3 = 1
     *
     * Sum = 2 + 2 + 3 = 7
     */
    int SumPrimeFactors(int n,std:: vector<int>& SPF){

        int sum = 0;

        // Continue factorization until n becomes 1
        while(n > 1){

            // Add smallest prime factor
            sum += SPF[n];

            // Remove that factor from n
            n /= SPF[n];
        }

        return sum;
    }

public:
    int smallestValue(int n) {

        // Precompute smallest prime factors
        std::vector<int> SPF = SmallestPrimeFactors(n);

        /*
         * Keep replacing n with sum of prime factors
         * until value becomes stable.
         */
        while(true){

            int sum = SumPrimeFactors(n, SPF);

            /*
             * If sum equals current number,
             * no further reduction is possible.
             *
             * This usually happens for prime numbers.
             */
            if(sum == n){
                return n;
            }

            // Update n and repeat process
            n = sum;
        }
    }
};

int main(){
    int n = 18;//output must be 5
    Solution sol1;
    int smallestVal = sol1.smallestValue(n);
    std::cout<<smallestVal;
    return 0;
}