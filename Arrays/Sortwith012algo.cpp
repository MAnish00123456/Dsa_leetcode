#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    std::vector<int> arr{1,0,2,1,1,0,1,2,0,2};
    int size=arr.size();
    //Brute force app O(nlogn)
    // std::sort(array.begin(),array.end());
    // for(int i=0;i<array.size();i++){
    //     std::cout<<array[i]<<"\t";
    // }

    //Slightly optimized approach , O(n)
//     int countzero=0,countone=0,counttwo=0;
//     for(int i=0;i<array.size();i++){
//         if(array[i]==0){
//             countzero+=1;
//         }
//         if(array[i]==1){
//             countone+=1;
//         }
//         if(array[i]==2){
//             counttwo+=1;
//         }
//     }
// std::cout<<countzero<<"\t"<<countone<<"\t"<<counttwo<<std::endl;
// int i=0;
// int n=array.size();
// while(i<n){
//     array.pop_back();
//     i++;
// }
// while(countzero>0){
//     array.push_back(0);
//     countzero--;
// }
// while(countone>0){
//     array.push_back(1);
//     countone--;
// }
// while(counttwo>0){
//     array.push_back(2);
//     counttwo--;
// }
//  for(int i=0;i<array.size();i++){
//         std::cout<<array[i]<<"\t";
//     }

//most optimized solution , TC=O(n) with sc =O(1)
//DUTCH NATIONAL FLAG ALGORITHM 
//we need to sort our array of 0's , 1's ,2's in on loop.
//isme hum imagine krte hai ki given array unsorted hai jiski range mid to high hoga
// and jo apne 0's hai vo 0 to low -1 tak hai and 1's hai vo low to mid-1 and 2's apne high +1 to size-1.
int low =0, mid =0 , high=size-1;
while(mid<=high){
    if(arr[mid]==0){
        std::swap(arr[low],arr[mid]);
        low++;
        mid++;
    }
    if(arr[mid]==1){
        mid++;
    }
    if(arr[mid]==2){
        std::swap(arr[mid],arr[high]);
        high--;
    }
}
std::cout<<"sorted array:"<<std::endl;
for(int elem:arr){
    std::cout<<elem<<"\t";
}
return 0;
}
