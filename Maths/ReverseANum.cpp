#include<iostream>

// (%) gives us remainder
// (/) gives us quotient
// fetch each digit from unit place from given number and then add it to revnum variable;
//revnum=0; , revnum=revnum*10+digit
//for ex , num=15
//digit=15%10 which gives 5
//revnum=0*10+5==5
//num=15/10==1
//digit=1%10==1
//revnum=5*10+1==51;
int reverseNUM(int num){
    int revnum=0;
    while(num!=0){
        int dig=num%10;
        revnum=revnum*10+dig;
        num=num/10;
    }
    return revnum;
}
int main(){
    int num;
    std::cout<<"Enter a number:"<<std::endl;
    std::cin>>num;
    int revnum=reverseNUM(num);
    std::cout<<"\n";
    std::cout<<"reversed num: "<<revnum;
}