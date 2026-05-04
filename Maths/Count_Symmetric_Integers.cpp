#include <iostream>
#include <string>

//Symmetric integers is an even length integer whose sum of first n digits are equal to sum of ending n digits.
//for ex-1203
//1+2==0+3

//as given range is small so these answers ok , for range more than this use digitDP

//Good for 1<=low<=high<=10000
int isSymmetric(int low, int high)
{
    int count = 0; // inital symmetric integers

    while (low <= high)
    {
        int num = low;
        std::string strnum = std::to_string(num);
        if (strnum.length() % 2 != 0)
        {
            low++;
            continue;
        }
        int i = 0;
        int j = strnum.length() / 2;
        int sum1 = 0;
        int sum2 = 0;
        while (i < strnum.length() / 2 && j < strnum.length())
        {
            int digit1 = strnum[i] - '0';
            int digit2 = strnum[j] - '0';
            sum1 += digit1;
            sum2 += digit2;
            i++;
            j++;
        }
        if (sum1 == sum2)
        {
            count++;
        }
        low++;
    }
    return count;
}


//one more method
int Count_symmetric(int low,int high){

}
int main()
{
    int low = 1200;
    int high = 1230;
    int Count_Symmetric_Integers = isSymmetric(low, high);
    std::cout << Count_Symmetric_Integers;
    return 0;
}