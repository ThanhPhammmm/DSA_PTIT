/*Done*/
#include <bits/stdc++.h>
using namespace std;

int maxSumNonAdjacent(const vector<int>& A, int N) {
    vector<long long> dp(N);

    dp[0] = A[0];  // Khởi tạo dp[0] là A[0]
    dp[1] = max(A[0], A[1]);  // dp[1] là phần tử lớn nhất giữa A[0] và A[1]

    for (int i = 2; i < N; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + A[i]);  // Chọn giữa không chọn A[i] hoặc chọn A[i] và dp[i-2]
    }

    return *max_element(dp.begin(), dp.end());  // Kết quả cuối cùng là dp[N-1]
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        cout << maxSumNonAdjacent(A, N) << endl;
    }

    return 0;
}
