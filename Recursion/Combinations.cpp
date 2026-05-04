//in this question we have given two integer values n and k 
//we have to return all possible combinations of k number of elements from range 1 to n

#include <iostream>
#include <vector>
    //By using n - (k - combination.size()) + 1 , it allows us to stop exploring branches that can never reach of size k
    //At any particular moment we know pur combination size(total nums included rn ) and required size(k)
    //numbers needed = k - combination.size()
    //for at any index i , we have remaining numbers(size) from i to n is  n-i+1 // for ex i =3 and n =5 , we have remaining nums = {3,4,5} , by formula 5-3+1 = 3
    //for a valid combination we want our remaining size >= numbers needed
    //so on replacing we got , n-i+1 >= k-size
    //it becomes i <=n-(k-size)+1 , pruning condition for loop

void combinations(std::vector<int> &Combination, int idx, int n, int k, std::vector<std::vector<int>> &Ans)
{
    //Base case when we got combination of k elements
    if(Combination.size() == k){
        Ans.push_back(Combination);
        return;
    }

    //we iterate for each num that can be possibly taken for our combinations , we prune our loop condtion and checks   only till we have enough numbers to make combination of k size  
    for(int i = idx ; i<=n -(k-Combination.size())+1 ; i++){
        Combination.push_back(i);
        combinations(Combination,i+1,n,k,Ans);

        Combination.pop_back();
    }

}

std::vector<std::vector<int>> Combine(int n, int k)
{if( k > n){
    return {};
}
    std::vector<int> Combination;
    std::vector<std::vector<int>> Ans;
    combinations(Combination, 1, n, k, Ans);
    return Ans;
}

int main()
{
    int n = 4;
    int k = 2;
    std::vector<std::vector<int>> Ans = Combine(n, k);
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