#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N), B(N);
        
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        sort(A.begin(), A.end());                // Sắp tăng A
        sort(B.begin(), B.end(), greater<long long>()); // Sắp giảm B

        long long result = 0;
        for (int i = 0; i < N; ++i) {
            result += A[i] * B[i];
        }

        cout << result << endl;
    }

    return 0;
}
