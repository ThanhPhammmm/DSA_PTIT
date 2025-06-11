#include <bits/stdc++.h>
using namespace std;

int precedence(char op){
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        stack<char> st;
        string result = "";
        for(int i = 0;i < s.length();i++){
            if(isalpha(s[i])){
                result += s[i];
            }
            else if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                while(st.top() != '('){
                    result += st.top();
                    st.pop();
                }
                st.pop();   //xoa dau '('
            }
            else{
                while(!st.empty() && precedence(st.top()) >= precedence(s[i])){
                    result += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        cout<<result<<endl;
    }
}