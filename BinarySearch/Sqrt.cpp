//in this question we have given a number x , a non negative integer , we need to return the square root of x rounded down to the nearest integer (non negative integer)
//we cant use inbuilt functions ,  for ex sqrt(5) = 2.23 rounded down to 2
//we will take help of binary search and find a number that is maximum and its square is nearest to our number by dividing search space in half on each iteration

#include<iostream>


int mySqrt(int num){
    if(num < 1){
        return num;
    }
    int low = 1 , high = num; // sqrt cannot be 0 for any positive integer so our low value starts from 1  and goes till our given num
    int ans =0;
    while(low <= high){
        long long mid = low + (high - low)/2;
        //if our mid square is closet or equal to our num we will store that answer and look for a bigger number which is near or equal to our given num
        if(mid * mid <= num){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return ans;
}

int main(){
    int num = 9;
    int ans = mySqrt(num);
    std::cout<<"ans: "<<ans;
    return 0;
}
