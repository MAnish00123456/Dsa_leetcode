// Given two strings s and t of lengths m and n respectively, return the minimum window substring of
//  s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

//use of sliding window trick 


#include<iostream>
#include<unordered_map>
#include<string>
#include<climits>

using ll = long long;
std::string minWindow(std::string& s , std::string& t){
    if(t.size() > s.size()) return "";

    //storing the frequency of t string , for which we need to find the min length which contain all characters in string s
    std::unordered_map<char,ll>Mapt;
    for(char ch : t) Mapt[ch]++;

    ll uniquecharcount = Mapt.size();

    ll startIdx = -1;
    ll windSt = 0 , windEnd = 0;
    ll min_len= (ll)INT_MAX;

    ll N = s.size();
    while(windEnd < N){
        
        //expansion phase
        //expanding our substring , till we get all unique character count with same frequency that we required of string t
        char ch = s[windEnd];
        if(Mapt.count(ch)){
            Mapt[ch]--;
            if(0 == Mapt[ch]){
                uniquecharcount--;
            }
        }

        //shrinking phase
        //shrink our valid substring from left till its valid and try to find a min length valid substring
        while(0 == uniquecharcount){
            ll len = windEnd - windSt + 1;
            if(len < min_len){
                min_len = len;
                startIdx = windSt;//start index for our min length  valid substring
            }

            ch = s[windSt];
            if(Mapt.count(ch)){
                Mapt[ch]++;
                //if frequency of the char is greater than 0 , it means iur window become invalid as our uniquecharcount increaes
                if(Mapt[ch] > 0){
                    uniquecharcount++;
                }
            }
            windSt++;
        }
        windEnd++;
    }
    return startIdx == -1?"":s.substr(startIdx,min_len);

}

int main(){
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    std::string Ans = minWindow(s,t);
    std::cout<<"Min window substr : "<<Ans;
    return 0;
}