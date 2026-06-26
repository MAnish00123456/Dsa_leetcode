

#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Solution
{
public:
    std::string minRemoveToMakeValid(std::string s)
    {
        std::stack<int> open;                 // store open bracket indices
        std::vector<char> vec(s.size(), ' '); // construct final string from this vector, it stores chars at their valid indices
        for (int i = 0; i < s.size(); i++)
        {
            if ('(' == s[i])
            {
                open.push(i);
            }
            else if (')' == s[i])
            {
                if (!open.empty() && '(' == s[open.top()])
                {
                    vec[open.top()] = '(';
                    vec[i] = ')';
                    open.pop();
                }
            }
            else
            {
                vec[i] = s[i];
            }
        }

        std::string ans = "";
        for (char ch : vec)
        {
            if (ch != ' ')
            {
                ans += ch;
            }
        }
        return ans;
    }
};

int main()
{
    std::string str = "lee(t(c)o)de)";
    Solution sol1;
    std::string ans = sol1.minRemoveToMakeValid(str);
    std::cout << ans;
    return 0;
}