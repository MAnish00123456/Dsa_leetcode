

#include<iostream>
#include<vector>
#include<algorithm>

//better approach, with O(n) SC and TC
int trap(std::vector<int>&height){
    if(height.empty()) return 0;
    int n = height.size();
std::vector<int>Leftmax(n) , Rightmax(n);
Leftmax[0]=0;
Rightmax[n-1]=0;
//for each height , we will find its boundaries(left , right) , both the boundaries should be max for that height 
//after that we will take the minimum of both boundaries and find our water trapped by subtracting our boundary - current height
//we only took min value because we know tha water can only be trapped with a smaller boundary value rather than a larger boundary
for(int i = 1 ; i<n; i++){
    Leftmax[i] = std::max(height[i-1] ,Leftmax[i-1]);
    Rightmax[n-i-1] = std::max(height[n-i] , Rightmax[n-i]);

}
int water = 0;
for(int i = 0;i<n;i++){
    int small = std::min(Leftmax[i] , Rightmax[i]);
    if(small > height[i]){
        water+=small - height[i];
    }
}
return water;
}

//optimal approach , 2 pointer approach , TC -> O(n) SC -> O(1)
int otrap(std::vector<int>&height){
int left = 0 , right = height.size()-1;//first pointer on first index and second on last index
int Lmax = 0 , Rmax = 0;//for each height we will store the running max height from left and right
int water = 0;
while(left <= right){
    Lmax = std::max(Lmax , height[left]);
    Rmax = std::max(Rmax , height[right]);
    if(Lmax < Rmax){
        // If left max is smaller, water level is limited by Lmax
        // So we can safely compute water at 'left'
        water += Lmax-height[left];
        left++;
    }
    else{
        // Right side is the limiting boundary
        // Water trapped depends on Rmax
        water += Rmax-height[right];
        right--;
    }
}
return water;
}

int main(){
    // std::vector<int> height = {4,2,0,3,2,5};
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // std::vector<int> height = {};
    int trappedWater = otrap(height);
    std::cout<<trappedWater<<std::endl;
    return 0;
}
