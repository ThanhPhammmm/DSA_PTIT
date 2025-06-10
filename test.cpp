#include <bits/stdc++.h>
using namespace std;

string result;

void Try(string s, int k){
    if(k == 0){
        return;
    }
    for(int i = 0;i < s.length() - 1;i++){
        for(int j = i + 1;j < s.length();j++){
            if(s[j] > s[i]){
                swap(s[j],s[i]);
                if(s > result){
                    result = s;
                }
                Try(s, k - 1);
                swap(s[j],s[i]);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--){
        int n; 
        string s;
        cin>>n>>s;
        result = s;
        Try(s, n);
        cout<<result<<endl;
    }
}
