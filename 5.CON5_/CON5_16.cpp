#include <bits/stdc++.h>
using namespace std;

int maxSumIncreasingSubsequence(vector<int>& A, int N) {
    vector<int> dp(N + 1);

    for(int i = 0;i < N;i++){
        dp[i] = A[i];
    }

    for(int i = 1;i < N;i++){
        for(int j = 0;j < i;j++){
            if(A[i] > A[j]){
                dp[i] = max(dp[i], dp[j] + A[i]);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int T; 
    cin >> T;
    while (T--) {
        int N; 
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        cout << maxSumIncreasingSubsequence(A, N) << endl;
    }
    return 0;
}
