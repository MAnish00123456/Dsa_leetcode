#include <iostream>
#include <climits>
bool isPalindrome(int num)
{
    int origNUM=num;
    int revnum = 0;
    while (num != 0)
    {
        int digit = num % 10;
        revnum = revnum * 10 + digit;
        num = num / 10;
    }
    if (revnum != origNUM)
    {
        return false;
    }
    return true;
}

int main()
{
    int num;
    std::cout << "Enter a number:" << std::endl;
    std::cin >> num;
    if (isPalindrome(num))
    {
        std::cout << "\n"
                  << num << " is palindrome";
    }
    else
    {
        std::cout << "\n"
                  << num << " is not palindrome";
    }
    return 0;
}