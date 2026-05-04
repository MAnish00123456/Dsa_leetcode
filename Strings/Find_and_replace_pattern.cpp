// this is similar problem to our isomorphic string , just use the same concept
//  Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
//  A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

std::vector<std::string> findAndReplacePattern(std::vector<std::string> &words,
                                     std::string pattern)
{
    std::vector<std::string> Ans;

    for (int i = 0; i < words.size(); i++)
    {
        std::string word = words[i];
        bool ok = true;
        std::unordered_map<char, char> wordTochar;
        std::set<char> usedchar;
        for (int j = 0; j < word.size(); j++)
        {
            char ch = pattern[j];
            char ma = word[j];
            if (!wordTochar.count(ma))
            {
                if (usedchar.find(ch) == usedchar.end())
                {
                    wordTochar[ma] = ch;
                    usedchar.insert(ch);
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                if (wordTochar[ma] != ch)
                {
                    ok = false;
                    break;
                }
            }
        }
        if (ok)
            Ans.push_back(word);
    }

    return Ans;
}

int main(){
    std::vector<std::string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    std::string pattern = "abb";
    std::vector<std::string>Ans = findAndReplacePattern(words,pattern);
    for(std::string str : Ans){
        std::cout<<"[ "<<str<<" ]"<<std::endl;
    }
    return 0;
}