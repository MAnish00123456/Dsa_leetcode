//to hume is problem me string ke words ko reverse karna hai, matlab last word first pe , firstlast pe in a way.
//for ex :- Hello World      output:- World Hello
//aur hume jitne bhi trailing spaces hinge  sabko hatana hai.
//to hum kya karenge ki pahle given string ko reverse kar denge and then us reversed string se ek ek word nikalenge usko reverse karenge and ans string me store kar denge.
// last me hum us ans ko return kar denge
#include<iostream>
#include<string>
#include<algorithm>

std::string ReverseWords(std::string s1){
    reverse(s1.begin(),s1.end());
    int n=s1.size();
    std::string ans="";
    for(int i=0;i<n;i++){
        std::string word="";
        while(i<n && s1[i]!=' '){
            word+=s1[i++];
        }
        reverse(word.begin(),word.end());
        if(word.size()>0){
            ans+=" "+word;
        }
    }
    return ans.substr(1);
}

int main(){
    std::string str1="  hello manish   kumar        ";
    // std::cout<<str1.length();
    std::string ansString=ReverseWords(str1);
    std::cout<<"Reverse words of given string : "<<"\n"<<ansString;
    return 0;
}