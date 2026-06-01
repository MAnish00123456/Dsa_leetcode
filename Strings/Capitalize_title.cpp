// You are given a string title consisting of one or more words separated by a single space, where each word consists of English letters. Capitalize the string by changing the capitalization of each word such that:

// If the length of the word is 1 or 2 letters, change all letters to lowercase.
// Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
// Return the capitalized title
\
// Input: title = "capiTalIze tHe titLe"
// Output: "Capitalize The Title"

#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>

class Solution {
    public:
        std::string capitalizeTitle(std::string title) {
            //make a stream of words using stringstream
            std::stringstream ss(title);
            std::string word;
            std::string Ans;
            while(ss >> word){//fetch a word from stream
            //if the size if equal to 2 or less , convert the word to lowercase
                if(word.size() < 3){
                    //use transform function with custom lambda expression
                    //[] is capture clause , used to include external vars in lambda function
                    //unsigned char c is parameter list , takes one char at a time from string
                    transform(word.begin(),word.end(),word.begin(),[](unsigned char c){return tolower(c);});
                }else{
                    //if word size if equal or greater than 3 use different lambda expression
                    //mutable ensures capture clause var can be modified withing expression body
                        transform(word.begin(),word.end(),word.begin(),[i=0](unsigned char c)mutable{return i++ == 0?toupper(c):tolower(c);});
                }
                    Ans+=word;
                    Ans+=" ";
            }
            Ans.pop_back();
            return Ans;
        }
    };

    int main(){
        std::string title = "hI mY NamE iS maNISh";
        Solution sol1;
        std::string Ans = sol1.capitalizeTitle(title);
        std::cout<<Ans<<std::endl;
        return 0;
    }