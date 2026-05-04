#include<iostream>
#include<vector>
 //for descending order printing just change condition < to > vice versa
int main(){
    //bubble sort mai adjacent elements ko check karke largest ko last mai push karte and ye chalta rahta 
    // for i iterations in outer loop , no of iteration in inner loop is n-i-1

//     std::vector<int> bubsort{4,1,5,2,3};
//     std::cout<<"Unsorted array:";
//     for (int i=0;i<bubsort.size();i++){
//         std::cout<<bubsort[i]<<" ";
//     }
//     int n=bubsort.size();
//     std::cout<<"\n"<<"Sorted array:";
//     bool isSwap=false;
//     for(int i=0;i<n-1;i++){
//         for(int j=0;j<n-i-1;j++){
//             if(bubsort[j]>bubsort[j+1]){
//             std::swap(bubsort[j],bubsort[j+1]);
//             isSwap=true;
//            }
//         }
//     if(!isSwap) break;
//     }
//    for (int i=0;i<bubsort.size();i++){
//         std::cout<<bubsort[i]<<" ";
//     }


//Selection Sort
// std::vector<int> selecsort{4,1,5,2,3};
// int n=selecsort.size();
//selection sort , array ko do hisso mai divide karta (sorted , unsorted) and unsorted me se hamesha ek min element nikalta and use sorted part mai push karta hai.
// no of iterations = n-1;
 
//  std::cout<<"Unsorted array:";
//     for (int i=0;i<selecsort.size();i++){
//         std::cout<<selecsort[i]<<" ";
//     }
// for(int i=0;i<n-1;i++){
//     int minIndex=i;
//     for(int j=i+1;j<n;j++){
//         if(selecsort[j]<selecsort[minIndex]){
//             minIndex=j;
//         }
//     }
//     std::swap(selecsort[i],selecsort[minIndex]);
// }
// std::cout<<"\n"<<"Sorted array:"<<" ";
//  for (int i=0;i<selecsort.size();i++){
//         std::cout<<selecsort[i]<<" ";
//     }


//Insertion sort
// assume 1st value is sorted, loop starts from 2nd value,store karenge vallue ko cuur var mai and ek prev pointer hoga jo point karega curr element ke pahle wale element pe
// check karenge using while loop ki jo prev pounter vali value hia kya badi hai curr value se if yes then hum prev pointer wali value push karenege aage ki taraf and prev ko decrement karnge
// phir se check karenge , after all checking hum curr var ki value ko sahi jagah put karenge that is prev+1 location pe
//total n-1 iterations
std::vector<int> Insertsort{4,1,5,2,3};
int n = Insertsort.size();
 std::cout<<"Unsorted array:";
    for (int i=0;i<Insertsort.size();i++){
        std::cout<<Insertsort[i]<<" ";
    }
//logic for sorting
for(int i=1;i<n;i++){//assuming 1st value is sorted
int curr=Insertsort[i];
int prev=i-1;
while(prev>=0&&Insertsort[prev]>curr){
    Insertsort[prev+1]=Insertsort[prev];
    prev--;
}
Insertsort[prev+1]=curr;
}
 std::cout<<"\n"<<"Sorted array:";
    for (int i=0;i<Insertsort.size();i++){
        std::cout<<Insertsort[i]<<" ";
    }







}