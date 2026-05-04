#include<iostream>
#include<string>

// Armstrong num is a number that is equal to sum of its digits ;each raised to power of number of digits
//For ex - 153 =1^3+5^3+3^3 or 1634=1^4+6^4+3^4+4^4
bool isArmStrongNum(int num){
    int sum=0;
    std::string strNum=std::to_string(num);
    int n=strNum.length();
    for(char ch:strNum){
        int calcdig=1;
        int digit=ch-'0';
        for(int j=1;j<=n;j++){
            calcdig*=digit;
        }
        sum+=calcdig;
    }
    return sum==num;    
}
int main(){
    int num;
    std::cout<<"Enter a number:"<<"\n";
    std::cin>>num;
    if(isArmStrongNum(num)){
        std::cout<<num<<" is an armstrong number";
    }
    else{
        std::cout<<num<<" is not an armstrong number";
    }
    return 0;
}