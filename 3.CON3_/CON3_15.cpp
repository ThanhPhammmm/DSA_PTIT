#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t; cin >> t;
    while(t--){
        int n, s, m;
        cin >> n >> s >> m;
        if(6*n < 7*m && s > 6) cout << -1 << endl;
        else if(s*m > (s - s/7)*n) cout << -1 << endl;
        else {
            cout << (s*m + n - 1) / n << endl;//công thức làm tròn lên
        }
    }
}