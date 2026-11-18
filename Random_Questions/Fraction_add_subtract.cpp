// Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

// The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

// Input: expression = "-1/2+1/2+1/3"
// Output: "1/3"

#include<iostream>
#include<string>
#include<stack>
using namespace std;
#include<numeric>

class Solution {
    public:
        string fractionAddition(string expression) {
            stack<int>st;
            int sign = 1;
         for(int i = 0 ; i < expression.size() ; i++){
            if(i == 0 && expression[i] == '-'){
                sign *= -1;
                continue;
            }
            while(i<expression.size() && (expression[i] != '-' && expression[i] != '+')){
                if(expression[i] != '/'){
                    int num = 0;
                    while(i<expression.size() && isdigit(expression[i])){
                     num = num*10 + expression[i]-'0';
                    i++;
                    }
                    st.push(num);
                    i--;
                }
                i++;
            }
            if(i < expression.size()){
            char op = expression[i];
            i++;
            int nu2 = 0;
            while(i<expression.size() && isdigit(expression[i])){
             nu2 = nu2*10 + expression[i]-'0';
             i++;
            }
            i++;
            int de2 = 0;
            while(i<expression.size() && isdigit(expression[i])){
             de2 = de2*10 + expression[i]-'0';
             i++;
            }
            i--;
            
            if(st.size() >= 2){
            int de1 = st.top();
            st.pop();
            int nu1 = st.top();
            st.pop();
    
    
            int mul = de1*de2;
            cout<<"mul : "<<mul<<endl;
            nu1 = (nu1*sign*(mul/de1));
            sign *= sign;
            nu2 = (nu2*(mul/de2));
            cout<<"mul : "<<mul<<endl;
            if(op == '+'){
                nu1 = nu1+nu2;
                // cout<<"nu1: "<<nu1<<endl;
            }else if(op == '-'){
                nu1 = nu1-nu2;
                // cout<<"nu1: "<<nu1<<endl;
            }
    
            if(nu1 != 0){
                // cout<<"push";
                st.push(nu1);
                st.push(mul);
            }
    
            }else{
                // cout<<"enter";
                string ans = "";
                int gcd_num = gcd(nu2,de2);
                nu2 /= gcd_num;
                de2 /= gcd_num;
                ans = to_string(nu2)+"/"+to_string(de2);
                return ans;
            }
            }
         }   
    string ans = "";
    if(!st.empty()){
    int fde = st.top();
    st.pop();
    int fnu = st.top();
    st.pop();
    int gcd_num = gcd(fnu,fde);
    cout<<fnu<<" "<<fde<<endl;
    fnu /= gcd_num;
    fde /= gcd_num;
    cout<<fnu<<" "<<fde<<endl;
    ans = to_string(fnu*sign) + "/" + to_string(fde);
    }
    
    
    return ans.empty()?"0/1":ans;
        }
    };

int main(){
    string expression = "-1/2+1/2+1/3";
    Solution sol1;
    cout<<sol1.fractionAddition(expression);
    return 0;
}