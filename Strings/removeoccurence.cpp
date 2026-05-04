//this question is about removing a str1 from str2 until all occurenece of str1 is removed
//isme hum string ka inbuilt method use karenge str.find and str.erase

#include<iostream>
#include<string>

std::string RemoveOccurence(std::string& str , std::string& part){
while(str.length()>0 && str.find(part)<str.length()){
    str.erase(str.find(part),part.length());
}
return str;
}

int main()
{
    std::string str = "hhvhvaahvahvhvaavhvaasshvahvaln";
    std::string part = "hva";
    std::string newstr=RemoveOccurence(str, part);
    std::cout << newstr;
    // auto index=str.find(part);
    // std::cout<<index;
    // str.erase(index,part.length());
    // std::cout<<str;
}