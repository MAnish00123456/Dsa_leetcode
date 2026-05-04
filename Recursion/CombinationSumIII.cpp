//Given question, we have given a k and n and range from 1-9
//we need to find combinations of k size whise sum is equal to our n , 
//This question is similar to Combinations and CombinationSumI and II 




#include<iostream>
#include<vector>
void Getallcombinations(int k , int target ,std::vector<int>&combination , std::vector<std::vector<int>>&Ans ,int idx ){
    
    //when there are no possible combinations of size k whose sum is equal to target or whether target becomes negative , we will return 
    if(idx > 9-(k-combination.size())+1 || target < 0){
        return;
    }
    
    // When combination size becomes equal to k and target becomes 0 , we got an answer
    if(combination.size() == k && target == 0){
        Ans.push_back(combination);
        return;
    }
    
    //Iteratively find all combinations
    for(int i = idx ; i <= 9-(k-combination.size())+1 ;i++){
        combination.push_back(i);//choose current num
        Getallcombinations(k,target-i,combination,Ans,i+1);//check if using current num , we are able to get combinations or not

        combination.pop_back();//Afteer a successful answer , we will backtrack to find other combinations
    }

}

std::vector<std::vector<int>> combinationSum3(int k , int target){
    std::vector<std::vector<int>>Ans;
    std::vector<int>combination;
    Getallcombinations(k,target,combination,Ans,1);
    return Ans;

}


int main()
{
    int n = 1;//target
    int k = 4;
    std::vector<std::vector<int>> Ans = combinationSum3(k,n);
    std::cout<<"Possible combinations : "<<std::endl;
    for(auto combination : Ans){
        std::cout<<"[";
        for(auto elem : combination){
            std::cout<<elem<<" ";
        }
        std::cout<<"]";
        std::cout<<"\n";
    }
    return 0;
}