//An optimal approach to calculate the count of prime numbers within a given range
#include<iostream>
#include<vector>

// we need to find count of prime numbers strictly less than the given number n
int CountPrimes(int n){
    std::vector<bool> isPrime(n+1,true);
    int count=0;
    for(int i=2;i*i<n;i++){
        if(isPrime[i]){
            count++;
            for(int j=i*i;j<n;j=j+i){
                isPrime[j]=false;
            }
        }
    }
    return count;
    }
int main(){
    int n=50;
    int count=CountPrimes(n);
    std::cout<<count;
}