//In this question , we have given a string s , we need to partition 's' such that every partition we get is palindromic or not,
//If the partition is palindrome , we will store it in answer . Return all possible partitions available
//For size 'n' , we can get n-1 partitions ,, if we start doing partitions from left and recursively check if that partition is palindrome or not
//to find partitions we can do , part = s.substr(0,i+1) , i pointer will help us to move partiiton


#include<iostream>
#include<string>
#include<vector>

bool isPalindrome(std::string part){
int left = 0 , high = part.length()-1;
while(left< high){
if(part[left] != part[high]){
    return false;
}
left++ , high--;
}
return true;
}



void GetAllPartitions(std::string s , std::vector<std::string>&Partition , std::vector<std::vector<std::string>>& Ans){
int n = s.size();
//Base Case
if(s.size() == 0){
Ans.push_back(Partition);
return;
}

//iteratively traverse on string for partitions
for(int i =0;i<n;i++){
    std::string part = s.substr(0,i+1);//consider part from left side
    //only consider given part if it is palindrome
    if(isPalindrome(part)){
        //include given partition
        Partition.push_back(part);
        //recursively check for more partitions
        GetAllPartitions(s.substr(i+1) , Partition , Ans);

        Partition.pop_back();//backtrack to get a new partition when our base case hits
    }
}

}

std::vector<std::vector<std::string>> partition(std::string s){
std::vector<std::string>Partition;
std::vector<std::vector<std::string>>Ans;
GetAllPartitions(s,Partition,Ans);
return Ans;

}

int main(){
    std::string s = "aab";
    std::vector<std::vector<std::string>> Partiions =partition(s);
    for(auto partition:Partiions){
        std::cout<<"[ ";
        for(auto part:partition ){
            std::cout<<part<<" ";
        }
        std::cout<<" ]";
        std::cout<<"\n";
    }
return 0;
}