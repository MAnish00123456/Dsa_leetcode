//Valid palindrome dekhna hai given problem mai. 
//Hum empty spaces , delimeters , special symbol sabko ignore karenge
#include<iostream>
#include<algorithm>
#include<string>

bool isAlnum(char st){
    if((st>=0 && st<=9) || (tolower(st)>='a' && tolower(st)<='z')){
        return true;
    }
    return false;
}

bool isPalindrome(std::string str){
    int st=0;
    int end=str.size()-1;
    while(st<end){
        if(!isAlnum(str[st])) {st++; continue;}
        if(!isAlnum(str[end])) {end--; continue;}
        if(tolower(str[st])!=tolower(str[end])){
            return false;
        }
        st++;
        end--;
    }
    return true;
}

int main(){
    std::string str;
    std::cout<<"Give a string : "<<"\n";
    getline(std::cin,str);
    if(isPalindrome(str)){
        std::cout<<"Given string is palindrome"<<std::endl;
    }
    else{
        std::cout<<"Given string is not palindrome"<<std::endl;

    }
    return 0;
}