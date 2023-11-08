#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int calculateExpression(string expression) {
    stack<int> stk;
    stringstream ss(expression);
    string token;
    
    while (getline(ss, token, ' ')) {
        if (isdigit(token[0])) {
            stk.push(stoi(token));  
        } else {
            int operand2 = stk.top();
            stk.pop();
            int operand1 = stk.top();
            stk.pop();
            
            int result;
            if (token == "+") {
                result = operand1 + operand2;
            } else if (token == "-") {
                result = operand1 - operand2;
            } else if (token == "*") {
                result = operand1 * operand2;
            } else {
                cout << "Invalid operator: " << token << endl;
                return 0;
            }
            
            stk.push(result);  
        }
    }
    
    return stk.top();
}

int main() {
    string expression;
    cout << "Enter the expression in postfix notation: ";
    getline(cin, expression);
    
    int result = calculateExpression(expression);
    cout << "Result: " << result << endl;
    
    return 0;
}
