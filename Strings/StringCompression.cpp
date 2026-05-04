//is problem me hum given string array ko coompress karna hai, char ke sath uska count store karna hai instead.
//for ex :-  chars={'a','a'.'b','b','c'}; and iska output hoga chars={'a','2','b','2','c'}; , hume given condition hai ki agar count 1 ho to sirf usi char ko store karenge but if its > 1 to 
//chars and uske count dono ko store karenge.
//Hume given array ki length and array return karna
#include<iostream>
#include<string>
#include<vector>

int StringCompression(std::vector<char>& chars){
int len=chars.size();
int Idx=0;
for(int i=0;i<len;i++){
    int count = 0;
    char ch=chars[i];
    while(i<len && chars[i]==ch){
        count++;
        i++;
    }
    if(count == 1){ 
        chars[Idx++]=ch;
    }
    else{
        chars[Idx++]=ch;
        std::string strCount=std::to_string(count);
        for(char ch:strCount){
            chars[Idx++]=ch;
        }
    }
    i--;
}
std::cout<<"Compressed String array : "<<std::endl;
for(char ch:chars){
    std::cout<<ch<<"\t";
}
return Idx;
}

int main(){
 std::vector<char> chars={'a','b','b','b','b','b','b','b','b','b','b','b','b'};
 std::cout<<"Given string array : "<<std::endl;
 for(char ch:chars){
    std::cout<<ch<<"\t";
 }
 std::cout<<"\n";
 int length=StringCompression(chars);
 std::cout<<"\n";
std::cout<<"length of the compressed string : "<<length;
}