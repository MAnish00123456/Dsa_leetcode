#include<iostream>

bool isPrime(int num){
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int num;
    std::cout<<"Enter a num:"<<std::endl;
    std::cin>>num;
    std::cout<<"\n";
    if(isPrime(num)){
        std::cout<<num<<" is a prime num"<<std::endl;
    }
    else{
        std::cout<<num<<" is not a prime num"<<std::endl;
    }
return 0;

}
