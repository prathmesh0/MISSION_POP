#include <iostream>
#include <stack>
using namespace std;

string postToInfix(string postfix) {
    stack<string> st;
    for(int i = 0; i < postfix.length(); i++) {
        if((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z')) {
            string temp = "";
            temp = postfix[i];
            st.push(temp);
        }
        else {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string exp = "";
            exp = '(' + s2 + postfix[i] + s1 + ')';
            st.push(exp);
        }
    }
    return st.top();
}

void inputPostfixExpression() {
    string postfixExp;
    cout << "Enter the postfix expression: ";
    cin >> postfixExp;

    string infixExp = postToInfix(postfixExp);

    cout << "Infix expression: " << infixExp << endl;
}

int main() {
    inputPostfixExpression();
    return 0;
}
