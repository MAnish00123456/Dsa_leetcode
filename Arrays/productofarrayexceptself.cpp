#include<vector>
#include<iostream>
using namespace std;
#include<climits>

//this will make s.c as O(n)
// vector<int> productExceptSelf(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> ans(n,1);
//         vector<int> prefix(n,1);
//         vector<int> suffix(n,1);
//         prefix[0]=1;
//         for(int i=1;i<n;i++){
//             prefix[i]=prefix[i-1]*nums[i-1];
//         }
//         suffix[n-1]=1;
//         for(int i=n-2;i>=0;i--){
//             suffix[i]=suffix[i+1]*nums[i+1];
//         }
//         for(int i=0;i<n;i++){
//             ans[i]=prefix[i]*suffix[i];
//         }
//       return ans;  
//  }
//ans below will  be of O(1) t.c space will be O(1) too
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
      int suffix=1;
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suffix*=nums[i+1];
            ans[i]*=suffix;
        }
      return ans;  
 }


 int main(){
    vector<int> nums= {1,2,3,4};
    vector<int> result=productExceptSelf(nums);
    int n =result.size();
    for(int i=0;i<n;i++){
        cout<<result[i]<<" "<<endl;
    }
 }