#include<iostream>
#include<string>
int main(){
    //string of characters
    // char str[]={'a','b','c','d','e','\0'};
    // char str1[]="ManishKumar";
    // char str2[100];
    // int len=0;
    // std::cin.getline(str2,100);//specially used for strings to take input with spaces
    // std::cin.getline(str2,100,'#');//# act as a delimiter which tells where to stop taking input
    // for(int i=0;str1[i]!='\0';i++){
    //     len+=1;
    // }
    // std::cout<<len<<std::endl;

    //string class
    // std::string str="hello world";
    std::string str;
    std::cout<<"enter string:"<<std::endl;
    getline(std::cin,str);
    std::cout<<str<<std::endl;
    return 0;
}