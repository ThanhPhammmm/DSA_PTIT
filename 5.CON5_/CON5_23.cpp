/*Done*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a, int n) {
    vector<int> dp(n, 1);

    for(int i = 0;i < n;i++){
        for(int j = 0;j < i;j++){
            if(a[j] <= a[i]){
                dp[i] = max(dp[i], dp[j] + 1);//Find the longest increasing subsequence
            }
        }
    }

    int lisLength = 0;
    for(int i = 0;i < n;i++){
        lisLength = max(lisLength, dp[i]);//Find the longest increasing subsequence length
    }

    return n - lisLength;//formula: original length - the longest increasing subsequence length
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(a, n) << endl;
    }
    return 0;
}
