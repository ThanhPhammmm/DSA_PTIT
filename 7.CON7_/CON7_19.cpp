/*Done*/
#include <bits/stdc++.h>
using namespace std;

void printMinNumber(string s) {
    stack<int> st;
    int num = 1;
    for(int i = 0;i <= s.length();i++){
        st.push(num++);
        if(i == s.length() || s[i] == 'I'){
            while(st.size() > 0){
                cout<<st.top();
                st.pop();
            }
        }
    }
    cout<<endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin>>s;
        printMinNumber(s);
    }

    return 0;
}
