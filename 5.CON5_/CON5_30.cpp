#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int minSquares(int N) {
    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    for(int i = 1;i <= N;i++){
        for(int j = 1;j * j <= i;j++){
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    return dp[N];
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << minSquares(N) << endl;
    }
    return 0;
}
