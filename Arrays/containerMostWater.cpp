#include<iostream>
#include<vector>
#include<climits>
int maxArea(std::vector<int>& height) {
        int mostwater=0;
        int n=height.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int base=j-i;
            int conheight=std::min(height[i],height[j]);
            int container=base*conheight;
            mostwater= std::max(mostwater,container);
            if(height[i]<height[j]){
                i++;}
                else{
                    j--;
                }
                }
                return mostwater;
            }
int main(){
    std::vector<int> height={1,8,6,2,5,4,8,3,7};
    std::cout<<"max water that can be stored is:"<<"\n";
    std::cout<<maxArea(height);
}
    