#include <iostream>
#include <stack>
using namespace std;

string prefixToInfixConversion(string &s) {
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            string temp = "";
            temp = s[i];
            st.push(temp);
        } else {
            string A = st.top();
            st.pop();
            string B = st.top();
            st.pop();
            string exp = '(' + A + s[i] + B + ')';
            st.push(exp);
        }
    }
    return st.top();
}

void inputPrefixExpression() {
    string prefixExp;
    cout << "Enter the prefix expression: ";
    cin >> prefixExp;

    string infixExp = prefixToInfixConversion(prefixExp);

    cout << "Infix expression: " << infixExp << endl;
}

int main() {
    inputPrefixExpression();
    return 0;
}
