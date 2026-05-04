#include <iostream>

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
// struct{
//     std::string name;
//     int age;
//     char grad;
// }details[3];
// int main(){
//     std::cout<<"Enter the details:\n";
//     for(int i =0;i<3;i++){
//         std::cout<<"Student "<<i+1<<":";
//         std::cin>>details[i].name>>details[i].age>>details[i].grad;
//     }
//     std::cout<<"\n";
//     std::cout<<"details:";
//     for(int i =0;i<3;i++){
//         std::cout<<"Student "<<i+1<<":\n";
//         std::cout<<"Name:"<<details[i].name<<"\n"<<"age:"<<details[i].age<<"\n"<<"grad:"<<details[i].grad;
//         std::cout<<"\n";
//     }

//     return 0;
// }

// pointers
int main(){
    int a =5;
    int* ptr=&a;
    std::cout<<a;
    std::cout<<&a<<"\n";
    std::cout<<ptr<<"\n";
    std::cout<<*(&a);
}