// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

// Constraints:

// 1 <= s.length <= 3 * 105
// s consists of digits, '+', '-', '(', ')', and ' '.
// s represents a valid expression.
// '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
// '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
// There will be no two consecutive operators in the input.
// Every number and running calculation will fit in a signed 32-bit integer.

//string can contain unary operators '-' , process it differently
//same logic as Basic_calculator_2  but this string have brackets and unary operator
//so process accordingly

#include<iostream>
#include<string>
#include<stack>

// At the start of expression -> '-' is unary
// After '('            -> '-' is unary
// After '+'            -> '-' is unary
// After '-'            -> '-' is unary

// After a number       -> '-' is binary
// After ')'            -> '-' is binary

class Solution {
    bool isNumber(char num) {
        if (num >= '0' && num <= '9') {
            return true;
        }
        return false;
    }

    int Prec(char token) {
        if ('+' == token || '-' == token) {
            return 1;
        }
        return 0;
    }

    long long ProcessCalculation(long long val1, long long val2, char op) {
        if ('+' == op) {
            return (val1 + val2);
        }
        return (val1 - val2);
    }

public:
    int calculate(std::string s) {
        std::stack<long long> Operands;
        std::stack<char> Operators;
        bool expect_operand = true;//start of the string  can be a number or an unary '-' 
        for (int i = 0; i < s.size(); i++) {
            // empty spaces
            if (s[i] == ' ')
                {continue;}

            // if s[i] is a number
            if (isNumber(s[i])) {
                std::string num = "";
                while (i < s.size() && isNumber(s[i])) {
                    num += s[i++];
                }
                i--;
                Operands.push(stoll(num));
                expect_operand = false;//next '-' can not be unary
            }

            else if (i < s.size()) {
                char token = s[i];
                // opening bracket , then insert it
                if ('(' == token) {
                    Operators.push(s[i]);
                    expect_operand = true;//next '-' can be unary
                }
                // closing bracket ')'
                else if (')' == token) {
                    while (Operands.size() >= 2 && !Operators.empty() &&
                           Operators.top() != '(') {
                        char op = Operators.top();
                        Operators.pop();

                        long long val2 = Operands.top();
                        Operands.pop();

                        long long val1 = Operands.top();
                        Operands.pop();

                        Operands.push(ProcessCalculation(val1, val2, op));
                    }
                    Operators.pop();
                    expect_operand = false;//next '-' will not be unary
                }
                // token is + or -
                else {
                    if('-' == token && expect_operand){
                        Operands.push(0);
                    }
                    while (Operands.size() >= 2 && !Operators.empty() &&
                           (Prec(token) == Prec(Operators.top()))) {
                        char op = Operators.top();
                        Operators.pop();

                        long long val2 = Operands.top();
                        Operands.pop();

                        long long val1 = Operands.top();
                        Operands.pop();

                        Operands.push(ProcessCalculation(val1, val2, op));
                    }
                    Operators.push(token);
                    expect_operand = true;
                }
            }
        }

        while (Operands.size() >= 2 && !Operators.empty()) {
            char op = Operators.top();
            Operators.pop();

            long long val2 = Operands.top();
            Operands.pop();

            long long val1 = Operands.top();
            Operands.pop();

            Operands.push(ProcessCalculation(val1, val2, op));
        }

        return Operands.empty()?0:static_cast<int>(Operands.top());
    }
};

int main(){
    std::string str = "(1+(4+5+2)-3)+(6+8)";
    Solution sol1;
    int Ans = sol1.calculate(str);
    std::cout<<Ans;
    return 0;
}