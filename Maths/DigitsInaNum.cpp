#include<iostream>
#include<string>
#include<algorithm>
void PrintDigit(int num){
    int sum=0;
    int sum1=0;
    while(num!=0){
        int digit=num%10;
        // std::cout<<digit<<"\t";
        sum+=digit;
         num=num/10;
    }
            while(sum>10){
            int digit1=sum%10;
            sum1+=digit1;
            sum=sum/10;
        }
    std::cout<<"sum:"<<sum;
}

int Sum(int num){
    // std::string str=std::to_string(num);
    // int sum=0;
    // int sum1=0;
    // for(int i=0;i<str.length();i++){
    //     int digit=str[i]-'0';
    //     sum+=digit;        
    // }
    //     std::string str1=std::to_string(sum);
    //     for(int i=0;i<str1.length();i++){
    //     int digit=str1[i]-'0';
    //     sum1+=digit;        
    // }
    int sum1=(num-1)%9+1;
    return sum1;
}
int main(){
    int num;
    std::cout<<"Enter the num: ";
    std::cin>>num;
    // PrintDigit(num);
    int sum=Sum(num);
    std::cout<<sum;
}