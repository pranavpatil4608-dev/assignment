
#include <iostream>
#include <stack>
using namespace std;

int power(int a, int b) {
    int result = 1;

    for (int i = 1; i <= b; i++) {
        result = result * a;
    }

    return result;
}

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' || ch == '^';
}

// INFIX TO POSTFIX
void infixToPostfix(char infix[], char postfix[]) {
    stack<char> s;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (ch >= '0' && ch <= '9') {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix[j++] = s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }
        else if (isOperator(ch)) {
            while (!s.empty() && s.top() != '(' &&
                  (precedence(s.top()) > precedence(ch) ||
                  (precedence(s.top()) == precedence(ch) && ch != '^'))) {
                postfix[j++] = s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix[j++] = s.top();
        s.pop();
    }

    postfix[j] = '\0';
}

// INFIX TO PREFIX
void infixToPrefix(char infix[], char prefix[]) {
    char reverse[100];
    char temp[100];
    char postfix[100];

    int n = 0;

    while (infix[n] != '\0') {
        n++;
    }

    for (int i = 0; i < n; i++) {
        reverse[i] = infix[n - 1 - i];

        if (reverse[i] == '(')
            reverse[i] = ')';
        else if (reverse[i] == ')')
            reverse[i] = '(';
    }

    reverse[n] = '\0';

    // Convert reversed expression to postfix
    stack<char> s;
    int j = 0;

    for (int i = 0; reverse[i] != '\0'; i++) {
        char ch = reverse[i];

        if (ch >= '0' && ch <= '9') {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix[j++] = s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }
        else if (isOperator(ch)) {
            while (!s.empty() && s.top() != '(' &&
                  (precedence(s.top()) > precedence(ch) ||
                  (precedence(s.top()) == precedence(ch) && ch == '^'))) {
                postfix[j++] = s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix[j++] = s.top();
        s.pop();
    }

    postfix[j] = '\0';

    for (int i = 0; i < j; i++) {
        prefix[i] = postfix[j - 1 - i];
    }

    prefix[j] = '\0';
}

// POSTFIX EVALUATION
int evaluatePostfix(char postfix[]) {
    stack<int> s;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        }
        else if (isOperator(ch)) {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            if (ch == '+')
                s.push(a + b);
            else if (ch == '-')
                s.push(a - b);
            else if (ch == '*')
                s.push(a * b);
            else if (ch == '/')
                s.push(a / b);
            else if (ch == '^')
                s.push(power(a, b));
        }
    }

    return s.top();
}

// PREFIX EVALUATION
int evaluatePrefix(char prefix[]) {
    stack<int> s;

    int n = 0;

    while (prefix[n] != '\0') {
        n++;
    }

    for (int i = n - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        }
        else if (isOperator(ch)) {
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (ch == '+')
                s.push(a + b);
            else if (ch == '-')
                s.push(a - b);
            else if (ch == '*')
                s.push(a * b);
            else if (ch == '/')
                s.push(a / b);
            else if (ch == '^')
                s.push(power(a, b));
        }
    }

    return s.top();
}

int main() {
    char infix[100];
    char postfix[100];
    char prefix[100];

    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << prefix << endl;

    cout << "Postfix Evaluation: "
         << evaluatePostfix(postfix) << endl;

    cout << "Prefix Evaluation: "
         << evaluatePrefix(prefix) << endl;

    return 0;
}
