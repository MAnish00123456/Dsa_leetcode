//in this problem we have given 2 string s1 and s2 , and whe have to check if there is any permutation of dtring s1 is present in string s2.
// if it is present then return true else return false, we have given that this problem have only small english alphabets present.
//ek string ki permutation agar dusri string me hogi to iska matlab same length and frequency of characters same honge.
//to given condition se hume pata chalta hai ki humare pass limited parameters hai to hum ek freqCount ka int type ka array banayege jisme hum store karenge occurenece of characters of string s1 and then 
//hum ek window banayenge s1 ke size ki and us window se hum string s2 me traverse karenge and har baar ek windCount array banayege , occurence ke liye and phir Freqcount and windcopunt ko compare karenge
// agar same hai to return true.
#include<iostream>
#include<string>
#include<vector>

bool isEqual(std::vector<int>Freqcount , std::vector<int>WindCount){
    for(int i=0;i<26;i++){
        if(Freqcount[i]!=WindCount[i]){
            return false;
        }
    }
    return true;
}


bool checkInclusion(std::string s1 , std::string s2){
    std::vector<int>Freqcount(26,0);
    for(int i=0;i<s1.size();i++){
        int idx=s1[i]-'a';
        Freqcount[idx]++;
}

int windSize=s1.size();

for(int j=0;j<s2.size();j++){
    int windIdx=0,Idx=j;
    std::vector<int> WindCount(26,0);
    while(windIdx<windSize && Idx<s2.size()){
        int charIdx=s2[Idx]-'a';
        WindCount[charIdx]++;
        windIdx++;
        Idx++;
    }
    if(isEqual(Freqcount,WindCount)){
        return true;
    }
}
return false;
}

int main()
{
    // we need to find if any permutation of str1 appears in str2 with same characters and the fdrequency
    std::string str1 = "ab";
    std::string str2 = "eidcaooo";
    if(checkInclusion(str1,str2)){ std::cout<<"permutation available"<<std::endl;}
    else {std::cout<<"permutation not avaiable";}
}