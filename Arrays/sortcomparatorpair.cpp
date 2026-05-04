#include<iostream>
#include<vector>
#include<algorithm>
bool comparator(std::pair<int,int>p1,std::pair<int,int> p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
  
    // if(p1.second==p2.second){
        if(p1.first<p2.first) return true;
        else return false;
    // }
}
int main(){
std::vector<std::pair<int,int>> num;
num.emplace_back(1,1);
num.emplace_back(2,8);
num.emplace_back(4,1);
num.emplace_back(2,1);
num.emplace_back(3,3);
std::sort(num.begin(),num.end(),comparator);
for(auto p:num){
    std::cout<<p.first<<"  "<<p.second<<std::endl;
}
}
