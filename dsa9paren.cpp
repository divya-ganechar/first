//check paranthesis in a given expression using stack

#include <iostream>
#include <stack>
using namespace std;

bool isValidExpression(const string& expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}
int main() {
    string expression;
    cout << "Enter an expression with parentheses, braces, and brackets: ";
    getline(cin, expression);

    if (isValidExpression(expression)) {
        cout << "The expression is valid.\n";
    } else {
        cout << "The expression is NOT valid.\n";
    }

    return 0;
}
