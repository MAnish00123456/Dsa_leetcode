// Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
// Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

//this problem is similar as Next permutation

// input = 101
// output = 110

#include<iostream>
#include<string>
#include<climits>
#include<algorithm>

class Solution {
    public:
        int nextGreaterElement(int n) {
            
            
            std::string Num = std::to_string(n);
            int pivot = -1;
            for(int i = Num.size()-2; i>=0 ; i--){
                if(Num[i] < Num[i+1]){
                    pivot = i;
                    break;
                }
            }
            if(pivot == -1)return -1;
    
            for(int i = Num.size()-1 ; i>= 0 ; i--){
                if(Num[i] > Num[pivot]){
                    std::swap(Num[i],Num[pivot]);
                    break;
                }
            }
    
            reverse(Num.begin()+pivot+1 , Num.end());
            long long num = stoll(Num);
            return num>INT_MAX?-1:static_cast<int>(num);
        }
    };

    int main(){
        int n = 101;
        Solution sol1;
        int NGE = sol1.nextGreaterElement(n);
        std::cout<<NGE;
        return 0;
    }