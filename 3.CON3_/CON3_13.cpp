#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t; cin >> t;
    while(t--){
        int d; cin >> d; d--;
        string s; cin >> s;
        int xau[200] = {0};
        for(char c : s) xau[c]++;
        int max_c = 0;
        for(int i = 'a'; i <= 'z'; i++) max_c = max(max_c, xau[i]);
        if(s.size() % d == 0){
            if(max_c > s.size()/d) cout << -1 << endl;
            else cout << 1 << endl;
        }
        else {
            if(max_c > s.size()/d + 1) cout << -1 << endl;
            else cout << 1 << endl;
        }
    }
}