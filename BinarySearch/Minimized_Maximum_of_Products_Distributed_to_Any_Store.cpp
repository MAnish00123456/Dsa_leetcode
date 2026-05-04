//This question is similar to koko eating bananas , we have to do this :->
// You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.
// You need to distribute all products to the retail stores following these rules:
// A store can only be given at most one product type but can be given any amount of it.
// After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
// Return the minimum possible x.

//what we do is to always guess our minimum x and try to find if we able to distribute our total products to every store or not
//we need to check if we are able to distribute our products with allowed capacity to our all stores with a store having atleast 1 quantity of the product

//for ex:-> Quantities = [11,6] and retail_stores = 6
//our min quantity that a store can have is 1 which  is our lower limit and max quantity a store can have is 11 which is our upper limit
//low = 1 , high = 11 ,Max_allowed_quantity = 3(im directly dry run the code for optimal ans) 
//so for 0th product which have quantity 11 , with given allowed capacity we need atmost 4 stores to distribute all our products , then for our 1st product having quantity
// 6 , with given allowed capacity we need atmost 2 stores to dsitribute all our products , so total stores we needed is 6 which is equal to given retail_store , so 3 is the min
//allowed quantity 



#include<iostream>
#include<vector>
#include<algorithm>

//function to check whether with given allowed quantity to a store , we are able to distribute our products to our n stores or not
bool isValid(std::vector<int>&Quantities,int retail_stores,int Max_allowed_quantity){
int store = 0;
for(int i = 0;i<Quantities.size();i++){
    store+=Quantities[i]/Max_allowed_quantity;
    if(Quantities[i] % Max_allowed_quantity != 0){
        store++;
    }
}
return store<=retail_stores;
}


int minimizedMaximum(std::vector<int>&Quantities , int retail_stores){
    int low = 1;//atleast one product has to be assigned to each store
    int high = *max_element(Quantities.begin(),Quantities.end());//max amount of product that can be assined to any store is the max quantity available
    int ans = -1;//to store the minimized maximum number of products
    while(low<=high){
        int mid = low + (high-low)/2;//mid represents our maximum amount of quantity of a product that can be distributed to a store
        if(isValid(Quantities,retail_stores,mid)){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}


int main(){
    std::vector<int> Quantities={11,6};
    int retail_stores = 6;
    int min_possible_quantity = minimizedMaximum(Quantities,retail_stores);
    std::cout<<min_possible_quantity<<std::endl;
    return 0;
}