#include <iostream>
#include <stack>
using namespace std;

string preToPost(string s) {
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            string temp = "";
            temp = s[i];
            st.push(temp);
        } else {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string exp = s1 + s2 + s[i];
            st.push(exp);
        }
    }
    return st.top();
}

void inputPrefixExpression() {
    string prefixExp;
    cout << "Enter the prefix expression: ";
    cin >> prefixExp;

    string postfixExp = preToPost(prefixExp);

    cout << "Postfix expression: " << postfixExp << endl;
}

int main() {
    inputPrefixExpression();
    return 0;
}
