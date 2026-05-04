// In this problem we have been given a integer value and we need to convert it into roman form , by applying rules of conversion
//  Addition Principle: When symbols are arranged in descending order of value, they are added together (e.g., XII = 12, LX = 60).
//  Subtractive Principle: To avoid repeating a symbol four times, a lower value symbol placed before a higher value symbol indicates subtraction. This is used only for the following pairs:
//   IV (4), IX (9), XL (40), XC (90), CD (400), and CM (900)
//  Repetition Limits: Powers of 10 (I, X, C, M) can appear consecutively at most 3 times.  Symbols V, L, and D cannot be repeated.
//   If a value requires four of the same symbol, the subtractive form must be used instead.

#include <iostream>
#include <string>
#include <vector>

std::string Integertoroman(int num)
{
    std::vector<std::pair<int, std::string>> romanMap = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    std::string res="";
   
    int dividend = num;
    int remainder = 0;
    int quotient = 0;
    for(const auto&it : romanMap){
        if(dividend == 0 ){
            break;
        }
        quotient = dividend / it.first;
        for (int i = 0; i < quotient; ++i) {
            res += it.second;
        }   
        dividend %=it.first;
    }
    return res;
}

int main(){
    int num = 3749;
    std::string result = Integertoroman(num);
    std::cout<<num <<" :-> "<<result;
    return 0;
}
