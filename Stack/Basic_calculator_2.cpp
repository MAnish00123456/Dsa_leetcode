// Given a string s which represents an expression, evaluate this expression and return its value. 
// The integer division should truncate toward zero.
// You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

// Input: s = "3+2*2"
// Output: 7

//As our expression is in form of infix expression (operand operator operand) form , the basic idea is to use 2 stacks , one for operands and one for operator,
//operator stack will maintain the precedence and associativity 

#include<iostream>
#include<string>
#include<stack>

class Solution {
    int ProcessCalculation(int val1, int val2, char op) {
        if (op == '+')
            return val1 + val2;
        if (op == '-')
            return val1 - val2;
        if (op == '*')
            return val1 * val2;
        if (op == '/') {
            if (val1 * val2 < 0 && val1 % val2 != 0) {
                return (val1 / val2) - 1;
            }
            return (val1 / val2);
        }
        return 0;
    }

    int Prec(char ch) {
        if (ch == '-' || ch == '+')
            return 1;
        if (ch == '*' || ch == '/')
            return 2;

        return -1;
    }

    bool isNumber(char token) {
        if (token >= '0' && token <= '9') {
            return true;
        }
        return false;
    }

public:
    int calculate(std::string s) {
        std::stack<int> Operands;
        std::stack<char> Operators;
        for (int i = 0; i < s.size(); i++) {
            //leave empty spaces
            if (s[i] == ' ') {
                continue;
            }
            if (isNumber(s[i])) {
                //build the number by parsing string, it can be 1 , 10 ,100 type
                std::string num = "";
                while (i < s.size() && isNumber(s[i])) {
                    num += s[i++];
                }
                i--;
                Operands.push(stoi(num));
            } else {
                char token = s[i];
                //maintain precedence , if top char has high precedence than perform operations using top operatore || if top operator have equal precedence to current operator , so by associativity , solve top operator first
                while (!Operators.empty() && Operands.size() >= 2 &&
                           (Prec(token) <= Prec(Operators.top())) ){
                    char op = Operators.top();
                    Operators.pop();
                    int val2 = Operands.top();
                    Operands.pop();
                    int val1 = Operands.top();
                    Operands.pop();
                    Operands.push(ProcessCalculation(val1, val2, op));
                }
                Operators.push(token);
            }
        }
        while (!Operators.empty() && Operands.size() >= 2) {
            char op = Operators.top();
            Operators.pop();
            int val2 = Operands.top();
            Operands.pop();
            int val1 = Operands.top();
            Operands.pop();
            Operands.push(ProcessCalculation(val1, val2, op));
        }
        return Operands.top();
    }
};

int main(){
    std::string str = "1+2-4*7/10+100";
    Solution sol1;
    int Ans = sol1.calculate(str);
    std::cout<<Ans<<std::endl;
    return 0;
}