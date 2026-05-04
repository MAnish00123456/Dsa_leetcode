//In this question , we hve given an integer array and a target value, we have to find the first and last occurrence of the target in given array, if there are no occurrences , we 
//will return {-1,-1}
//We will run two binary search for finding both first and last occurrence , for each index to find we will use binary search

//problems like:->
//  first occurrence
// last occurrence
// range of target
// count of target
// lower bound + upper bound
//for problems like these , we will always use binary search twice as in single pass we will get only one index

#include<iostream>
#include<vector>

std::vector<int> searchRange(std::vector<int>& nums, int target) {
    //To solve this problem , we will apply binary search twice , first we will find our leftmost index where target exists and then secondly we will find our rightmost index where our target exists. 
        
        int low = 0 , high = nums.size()-1 , first = -1;
        //1st -> Binary search to find our leftmost index ,  we will shrink our search space to the left side
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] >= target){
                high = mid -1;//when we find our occurence we store this index and try to find if our target exists in leftmost space or not
            }
            else{
                low = mid + 1;//if our nums[mid] < target , our target will  probably be present in right side
            }
            if(nums[mid] == target){
                first = mid;//storing our index whenever we find our target , until we find our leftmost index
            }
        }
    
        //2nd -> Binary search again to find our rightmost index , we will shrink our search space to the right side 
         low = 0 , high = nums.size()-1 ;
         int last = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]<=target){
                low = mid + 1; // when we find our occurence we store this index , and try to find if our target exists in rightmost space or not
            }
            else{
                high = mid -1;//if our nums[mid] > target , our target will be present in left side
            }
            if(nums[mid] == target){
                last = mid;//storing our index whenever we find our target , until we find our rightmost index
            }
        }
        return {first,last};
    
        }

        int main(){
            std::vector<int> nums = {1,2,3,3,3,3,3,4,5,6,7};
            int target = 3;
            std::vector<int> Indices = searchRange(nums,target);
            std::cout<<"First indice for value " <<target<<" is : "<<Indices[0]<<std::endl;
            std::cout<<"Last indice for value " <<target<<" is : "<<Indices[1]<<std::endl;
            return 0;
        }