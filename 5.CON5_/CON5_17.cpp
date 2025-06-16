/*Done*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a){
    int n = a.size();
    vector<int> inc(n);
    vector<int> dec(n);

    for(int i = 0;i < n;i++){
        inc[i] = a[i];
        dec[i] = a[i];
    }

    for(int i = 1;i < n;i++){
        for(int j = 0;j < i;j++){
            if(a[i] > a[j]){
                inc[i] = max(inc[i], inc[j] + a[i]);
            }
        }
    }

    for(int i = n - 2;i >= 0;i--){
        for(int j = n - 1;j > i;j--){
            if(a[i] > a[j]){
                dec[i] = max(dec[i], dec[j] + a[i]);
            }
        }
    }
    
    int res = 0;
    for(int i = 0;i < n;i++){
        res = max(res, inc[i] + dec[i] - a[i]);
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0;i < n;i++){
            cin>>a[i];
        }

        int res = solve(a);
        cout<<res<<endl;
    }
}