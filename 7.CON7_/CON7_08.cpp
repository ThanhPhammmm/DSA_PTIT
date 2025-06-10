#include <bits/stdc++.h>
using namespace std;

string solve(string &s){
    stack<char> tmp;

    for(int i = 0;i < s.length();i++){
        if(s[i] == '('){
            tmp.push(i);
        }
        else if(s[i] == ')'){
            if(s[(tmp.top() - 1)] == '-'){
                for(int j = tmp.top() + 1;j < i;j++){
                    if(s[j] == '+'){
                        s[j] = '-';
                    }
                    else if(s[j] == '-'){
                        s[j] = '+';
                    }
                }
            }
            tmp.pop();
        }
    }

    string res = "";
    for(char c : s){
        if(c != ')' && c != '('){
            res.push_back(c);
        }
    }

    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }
}