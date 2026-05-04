// Next permutation nikalna hai hume isproblem me , permutation apna combination of given nums or char. Hume lexicographically next permutation nikalna hai.
//agar koi permutation available na ho to given vector ko reverse krke return karenge.
//for ex = { 1,2,3 }
//to iska next permutation hoga vo ={ 1,3,2 }
//Agar given array ko hum backward travel karenge  to ek point aisa aayega jo apne next point se bada hoga. Vo humara Pivot hoga.
//Pivot milne ke baad , rightmost element lenge jo pivot se just bada hoga , uske sath hum pivot ko swap kar denge.
// phir pivot + 1 se size -1 wale elements ko reverse kar denge
#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> NextPermutation(std::vector<int> Arr){
    //Given array me single element hai
    if(Arr.size()<2) return Arr;
    
    //Ab pivot dhundna
    int size=Arr.size();
    int pivot=-1;
    for(int i=size-2;i>=0;i--){
        if(Arr[i]<Arr[i+1]){
            pivot=i;
            break;
        }
    }

    // agar pivot na mile
    if(pivot==-1) {
        std::reverse(Arr.begin(),Arr.end());
        return Arr;
    }

    //Jaise hi pivot mil jayega , tab hum pivot se rightmost ek element dhundna jo pivot se just bada hoga
    for(int i=size-1;i>pivot;i--){
        if(Arr[i]>Arr[pivot]){
            std::swap(Arr[i],Arr[pivot]);
            break;
        }
    }

    //Ab swap karne ke baad hum pivot+1 se size-1 tak ke elements ko reverse krdenge;
    int st=pivot+1;
    int end=size-1;
    while(st<end){
        std::swap(Arr[st],Arr[end]);
        st++;
        end--;
    }

    //ab return kardenge
    return Arr;
    
}

int main(){
    std::vector<int> Arr={1,2,3,6,5,4};
    std::cout<<"Given Array : "<<std::endl;
    for(int elem:Arr){
        std::cout<<elem<<"\t";
    }
    std::cout<<"\n";
    std::cout<<"Next permutation of given Array : "<<std::endl;
    std::vector<int> NextPermuArr= NextPermutation(Arr);
    for(int elem:NextPermuArr){
        std::cout<<elem<<"\t";
    }
    return 0;
}