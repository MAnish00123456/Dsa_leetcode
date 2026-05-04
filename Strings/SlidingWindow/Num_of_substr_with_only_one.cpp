// Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 1e9 + 7.

#include <iostream>
#include <string>

//code by me
int numSub(std::string &str)
{
    int mod = 1e9 + 7;
    long long count = 0;
    int l = 0;         // left boundary of valid window
    int zerocount = 0; // number of zeroes inside window
    for (int i = 0; i < str.length(); i++)
    {
        // if current char is 0 , then current window do not have only 1s
        if (str[i] == '0')
            zerocount++;
        // skip to a valid window with all 1s
        while (zerocount > 0)
        {
            if (str[l] == '0')
            {
                zerocount--;
            }
            l++;
        }
        // If s[i] is '1', then all substrings ending at i
        // and starting from l to i are valid
        if (str[i] == '1')
        {
            count += i - l + 1;
            count = count % mod;
        }
    }
    return (int)count;
}

//a lil clean code
int CnumSub(std::string& s) {
    long long count = 0;
    int mod = 1e9 + 7;
    int l = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            l = i + 1;   // next valid substring can only start after this 0
        } else {
            count = (count + (i - l + 1)) % mod;
        }
    }

    return (int)count;
}

int main()
{
    std::string str = "0110111";
    int count = CnumSub(str);
    std::cout << "count : " << count;
    return 0;
}