//Merge 2 sorted array
//in this problem we  have given 2 array 'A' and 'B' with size m+n and n specifically.
// we need to merge both arrays and store it in array 'A'.
//we will proceed backwardly and compare elements of 'A' and 'B' and merge accordingly

#include<iostream>
#include<vector>

std::vector<int> MergeArray(std::vector<int>& A , std::vector<int>& B , int szA, int szB){
int idx=szA+szB-1;
int i=szA-1;
int j=szB-1;
while(i>=0 && j>=0){
    if(A[i]>B[j]){
        A[idx]=A[i];
        i--;
        idx--;
    }
    else{
        A[idx]=B[j];
        idx--;
        j--;
    }
}
while(j>=0){
    A[idx]=B[j];
    idx--;
    j--;
}
return A;
}

int main(){
    std::vector<int> A={3,4,6,9,10,19,0,0,0,0};
    std::vector<int> B={1,2,4,5};
    int szA=6;
    int szB=B.size();
    std::cout<<"Array 'A' : "<<std ::endl; 
    for(int elem : A){
        std::cout<<elem<<"\t";
    }
    std::cout<<"\n";
    std::cout<<"Array 'B' : "<<std ::endl; 
    for(int elem : B){
        std::cout<<elem<<"\t";
    }
    std::cout<<"\n";

    std::cout<<"Arrays after merging : "<<std::endl;
    std::vector<int> mergedarray= MergeArray(A,B,szA,szB);
    for(int elem : mergedarray){
        std::cout<<elem<<"\t";
    }
    return 0;
}