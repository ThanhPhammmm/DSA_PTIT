/*Done*/
/*Cach1*/
#include<bits/stdc++.h>
using namespace std;

const int MAX_S = 40005; // S <= 40000

bool dp[MAX_S];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, S;
        cin >> n >> S;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        // reset dp
        for (int i = 0; i <= S; i++) dp[i] = false;
        dp[0] = true; // tổng 0 luôn đạt được

        for(int i = 0;i < n;i++){
            for(int j = S;j >= 0;j--){
                if(dp[j - a[i]]){
                    dp[j] = true;
                }
            }
        }

        if (dp[S]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/*-------------------------------------------------------------------*/

/*Cach2*/
#include <bits/stdc++.h>
using namespace std;

bool ok = 0;

void Try(vector<int>& a, int n, int s, int current, int index){
    if(current > s || ok == 1){
        return;
    }
    if(current == s){
        ok = 1;
        return;
    }
    if(index > n) return;
    Try(a, n, s, current + a[index], index + 1);

    Try(a, n, s, current, index + 1);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, s;
        cin>>n>>s;
        vector<int> a(n + 1);
        for(int i = 0;i < n;i++){
            cin>>a[i];
        }
        Try(a, n, s, 0, 0);
        if(ok) cout <<"YES"<<endl;
        else cout<<"NO"<<endl;
        ok = 0;
    }
}
