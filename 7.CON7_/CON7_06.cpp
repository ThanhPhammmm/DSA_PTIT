/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin>>s;
        stack<char> temp;
        bool ok = 1;
        for(char c : s){
            if(c == '(' || c == '+' || c == '-' || c == '*' || c == '/'){
                temp.push(c);
            }
            else if(c == ')'){
                if(temp.top() == '('){
                    ok = 0;
                    break;
                }
                else{
                    while(temp.top() != '('){
                        temp.pop();
                    }
                    temp.pop();
                }
            }
        }
        if(ok == 0){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}