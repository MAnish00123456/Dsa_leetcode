//in this question we have given two string s and p , and we need to find all valid anagrams of p present into s. Return an ans array with starting indices of each valid anangrams 
//for ex -> p ="ab" , s="abab"
// so Ans = [0,1,2] , as these are staring indices of valid anagrams

// we can solve this using fixed size sliding window patter , where we will find valid anagram for first k char(k = size of p) in s . the another loop starting from k upto size of s , and 
//expand and shrink window and checking validity everytime 

#include<iostream>
#include<string>
#include<vector>

bool isEqual(int Freqar[],int Freqarr[]){
    for(int i = 0 ; i < 26 ; i++){
        if(Freqar[i] != Freqarr[i]){
            return false;
        }
    }
    return true;

}
std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int> ans;
    if(p.size() > s.size()) return ans;

    int freqP[26] = {0};
    int freqS[26] = {0};

    for(char ch : p) freqP[ch - 'a']++;

    int k = p.size();

    // first window
    for(int i = 0; i < k; i++) {
        freqS[s[i] - 'a']++;
    }

    if(isEqual(freqP, freqS)) ans.push_back(0);

    // slide the window
    for(int i = k; i < s.size(); i++) {
        freqS[s[i] - 'a']++;         // add new char
        freqS[s[i - k] - 'a']--;     // remove old char

        if(isEqual(freqP, freqS)) {
            ans.push_back(i - k + 1);
        }
    }

    return ans;
}
int main(){
    // std::string p= "abc";
    std::string p= "ab";
    // std::string s= "cbaebabacd";
    std::string s= "abab";
    std::vector<int>Ans = findAnagrams(s,p);


    for(int val : Ans){
        std::cout<<val<<"  ";
    }
}
