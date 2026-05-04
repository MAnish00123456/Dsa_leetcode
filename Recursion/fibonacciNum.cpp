#include<iostream>
#include<vector>
int fib(int n) {
    //Recurrence relation 
    //F(n) = F(n-1) + F(n-2) , with n starting from 3
    //Base case would be 
    //F(n)=0 for n =1 and F(n)=1 for n =2
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1   ;
    }  
    // return (fib(n-1) + fib(n-2));
    
        std::vector<int> Tr(n + 1, 0);
        Tr[0] = 0;
        Tr[1] = 1;
        Tr[2] = 1;
        if (n == 0)
            return Tr[0];
        if (n == 1 || n == 2)
            return Tr[1];
        for(int i = 3 ; i<=n ;i++){
            Tr[i] = Tr[i-1] + Tr[i-2] + Tr[i-3];
        }
        return Tr[n];
    }

    int main(){
        int n =35;
        int term = fib(n);
        std::cout<<n<<"th term is : "<<term<<std::endl;
        return 0;
    }