#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return ((c == '+') || (c == '-') || (c == '*') || (c == '/'));
}

string prefixToInfix(string exp){
    stack<string> rs;
    for(int i = 0;i < exp.length();i++){
        char c = exp[i];
        if(isOperator(c)){
            string s1 = rs.top();
            rs.pop();
            string s2 = rs.top();
            rs.pop();
            string s3 = '(' + s2 + c + s1 + ')';
            rs.push(s3); 
        }
        else{
            string temp = "";
            temp += c;
            rs.push(temp);
        }
    }
    return rs.top();
}
int main() {
    int T;
    cin >> T;

    while (T--) {
        string exp;
        cin>>exp;
        cout << prefixToInfix(exp) << "\n";
    }

    return 0;
}
