// Given two binary strings a and b, return their sum as a binary string.
#include <iostream>
#include <string>
#include <algorithm>

class Binary
{
public:
    std::string addBinary(std::string &a, std::string &b)
    {
        int carry = 0;
        std::string sum = "";
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0)
        {
            int val1 = 0, val2 = 0;
            if (i >= 0)
            {
             val1 = a[i--] - '0';
            }
            if (j >= 0)
            {
             val2 = b[j--] - '0';
            }
            int total = val1 + val2 + carry;
             sum += (total % 2) + '0';
            carry = total / 2;
        }
        if(carry) sum+='1';
        std::reverse(sum.begin(), sum.end());
        return sum;
    }
};

int main()
{
    Binary sum1;
    std::string s1 = "1010";
    std::string s2 = "1011";
    std::string sum = sum1.addBinary(s1, s2);
    std::cout << "addition : " << sum;
    return 0;
}