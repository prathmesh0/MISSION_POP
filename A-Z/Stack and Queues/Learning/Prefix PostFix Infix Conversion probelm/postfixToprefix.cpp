#include <iostream>
#include <stack>
using namespace std;

string postfixToPrefix(string &s){
    stack<string> st;
    for(int i = 0; i < s.length(); i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            string temp = "";
            temp = s[i];
            st.push(temp);
        }
        else{
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string exp = s[i] + s2 + s1;
            st.push(exp);
        }
    }
    return st.top();
}

void inputPostfixExpression() {
    string postfixExp;
    cout << "Enter the postfix expression: ";
    cin >> postfixExp;

    string prefixExp = postfixToPrefix(postfixExp);

    cout << "Prefix expression: " << prefixExp << endl;
}

int main() {
    inputPostfixExpression();
    return 0;
}
