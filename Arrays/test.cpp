#include<iostream>
#include<vector>

int main(){
std::vector<int> nums= {4,3,2,7,8,2,3,1};
int n = nums.size();
int xor1=0;
for(int val : nums){
    xor1^val;
}
for(int i = 1 ; i <=n ; i++){
    xor1^i;
}
std::cout<<xor1;
}