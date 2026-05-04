#include <iostream>

// GCD and HCF are same. it is a highest value that can divide both given a and b

// This is a brute force approach to calculate gcd
int GCD(int a, int b)
{
    int gcd = 1;
    std::cout << "function called";
    if (a == 0)
    {
        gcd = b;
    }
    if (b == 0)
    {
        gcd = a;
    }
    if (a == b)
    {
        gcd = a;
    }
    for (int i = 1; i <= std::min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

// Better approach , using modulus method,,,---> gcd(a,b) = gcd(a%b,b) if a>b
//                                                         = gcd(a,b%a) if b>a
//  and if a==0 gcd=b or if b==0 gcd=a
int optimalGCD(int a, int b)
{
    if (a == b)
    {
        return a;
    }
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else 
        {
            b = b % a;
        }
    }
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
}

//LCM = least/lowest common multiple 
//a*b=GCD(a,b)*LCM(a,b)
int LCM(int a, int b){
    int gcd=optimalGCD(a,b);
    int lcm=(a*b)/gcd;
    return lcm;
}

int main()
{
    int a, b;
    std::cout << "Enter values of a and b:" << std::endl;
    std::cin >> a >> b;
    int gcd = optimalGCD(a, b);
    int lcm=LCM(a,b);
    std::cout << "\n";
    std::cout << "gcd of " << a << " and " << b << " is:" << gcd<<std::endl;
    std::cout << "lcm of " << a << " and " << b << " is:" << lcm<<std::endl;
}