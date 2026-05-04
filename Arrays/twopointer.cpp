#include <iostream>
#include <climits>
#include<algorithm>
// int main() {
//   std::string pin;
//   std::cout<<"Enter a 4 digit pin:";
//   std::cin>>pin;
//   while(pin!="0125"){
//     std::cout<<"enter pin again:";
//     std::cin>>pin;
//   }
//   if(pin=="0125"){
//     std::cout<<"you got access";
//   }
//   return 0;
// }
// int main()
// {
//   int n;
// std::cout<<"enter size:";
// std::cin>>n;
// int arr[n];
// for(int i=0;i<n;i++){
//   std::cout<<"number:"<<i+1<<"\n";
//   std::cin>>arr[i];
// }
// std::cout<<"\n";
// for(int j=0;j<n;j++){
// std::cout<<arr[j]<<"\n";
// }
// }
// int MIn_MAx(int n){
// int arr[n];
// std::cout<<"Enter elements"<<"\n";
// int i,j;
// for( i=0;i<n;i++){
// std::cin>>arr[i];
// }
// int smallest=INT_MAX;
// int largest=INT_MIN;
// int smallest_number_index,largest_number_index;
// for(i=0,j=0;i<n,j<n;i++,j++){
//  smallest_number_index=std::min(arr[i],smallest);
//   largest_number_index=std::max(arr[j],largest);
// }
// return i;
// }
// int main(){
// int n;
// std::cout<<"Enter size of an array:"<<std::endl;
// std::cin>>n;
// int index=MIn_MAx(n);
// std::cout<<"smallest value index:"<<index<<"\t";
// }
int main(){
  int arr[]={4,2,7,8,1,2,5};
  int i,j;
  int n=sizeof(arr)/sizeof(arr[0]);
  std::cout<<"original:"<<"\n";
  for(i=0;i<n;i++){
  std::cout<<" "<<arr[i];
  }
  for(i=0,j=n-1;i<j;i++,j--){
    std::swap(arr[i],arr[j]);
  }
std::cout<<"\n"<<"reversed:"<<"\n";
 for(i=0;i<n;i++){
  std::cout<<" "<<arr[i];
  }
} 