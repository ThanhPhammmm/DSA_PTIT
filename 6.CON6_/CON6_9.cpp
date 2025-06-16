/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n, k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i = 0;i < n;i++){
            cin>>a[i];
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                if(a[j] + a[i] == k){
                    ans += 1;
                }
            }
        }
        cout<<ans<<endl;
    }
}