#include <bits/stdc++.h>
using namespace std;

void solve(string &s){
    stack<int> temp;

    for(int i = 0;i < s.length();i++){
        if(s[i] == '('){
            temp.push(i);
        }
        else if(s[i] == ')'){
            if(s[temp.top() - 1] == '-'){
                for(int j = temp.top() + 1;j < i;j++){
                    if(s[j] == '+'){
                        s[j] = '-';
                    }
                    else if(s[j] == '-'){
                        s[j] = '+';
                    }
                }
            }
            temp.pop();
        }
        
    }

    string res = "";
    for(int i = 0;i < s.length();i++){
        if(s[i] != '(' && s[i] != ')'){
            res += s[i];
        }
    }
    s = res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string p1, p2;
        cin>>p1>>p2;
        solve(p1);
        solve(p2);
        cout<<(p1 == p2 ? "YES" :"NO" )<<endl;
    }
}