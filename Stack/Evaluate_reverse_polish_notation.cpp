// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.

//also known as postfix notation

#include<iostream>
#include<vector>
#include<string>
#include<stack>

class Solution {
    bool isNumber(std::string num){
        size_t start = 0;
            if('-' == num[0] || '+' == num[0]){
                if(num.size() == 1)return false;
                 start = 1;
            }
            for(int i = start ; i < num.size() ; i++){
                if(!isdigit(static_cast<unsigned char>(num[i])))return false;
            }
            int val = stoi(num);

        return (val >= -200) && (val <= 200);
    }
    int ProcessCalculation(int val1 , int val2 , std::string op){
        if("+" == op){
            return (val1+val2);
        }
        if("-" == op){
            return (val1-val2);
        }
        if("/" == op){
            return (val1/val2);
        }
        return (val1*val2);
    }
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int>Operands;
        int val1 = -1 ; int val2 = -1;
        for(int i = 0 ; i < tokens.size() ; i++){
            if(isNumber(tokens[i])){
                Operands.push(stoi(tokens[i]));
            }else{
                std::string op = tokens[i];
                if(Operands.size() >= 2){
                     val2 = Operands.top();
                    Operands.pop();
                     val1 = Operands.top();
                    Operands.pop();
                }
                    Operands.push(ProcessCalculation(val1,val2,op));
            }
        }
        return Operands.empty()?0:Operands.top();
    }
};

int main(){
    std::vector<std::string>tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution sol1;
    int Ans = sol1.evalRPN(tokens);
    std::cout<<Ans;
    return 0;   
}