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
