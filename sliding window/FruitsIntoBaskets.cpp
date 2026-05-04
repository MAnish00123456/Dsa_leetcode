// in this problem we have been given a array called fruits and at each fruits[i] is the type of fruit the ith tree produces.
// We have been given 2 baskets and we have to take as many fruits as we can using those 2 baskets.
// Given the condition :-  each basket can hold only 1 type of fruit  , however there is no limit of the amount of the fruit stored in the basket .
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
//  Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// return the maximum number of fruits (aka lenght of a part of array which satisfy condition) we can pick

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
int totalFruit(std::vector<int> &Fruits)
{
    //This problem is indirectly called as Longest subarray with 2 distinct integers
    int n = Fruits.size();
    int l = -1; // starting index of window from left
    int Maxlength = 0;
    // use map as our basket to store the type and amount of the fruit
    std::unordered_map<int, int> Basket;
    for (int i = 0; i < n; i++)
    {
        Basket[Fruits[i]]++;//storing and updating the amount value for each fruit type
        while(Basket.size()>2){//if any point our basket size becomes greater than 2 , then we will start shrinking our window, i.e we are removing the starting type of fruit from the basket to validate the condition
            l++;
            Basket[Fruits[l]]--;//removing all the amounts of fruit we have got
            if(Basket[Fruits[l]] == 0){
                Basket.erase(Fruits[l]);//erasing that type of fruit to empty basket 
            }
        }
        Maxlength = std::max(Maxlength , i-l);//for each iteration , we are finding our longest subarray length satisfying the condition
    }
    return Maxlength;
}

int main()
{
    std::vector<int> Fruits = {1, 2, 3, 2, 2};
    int totalfruits = totalFruit(Fruits);
    std::cout << "Total no of fruits : " << totalfruits << std::endl;
    return 0;
}