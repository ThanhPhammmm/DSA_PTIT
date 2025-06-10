#include<bits/stdc++.h>

using namespace std;

bool isSortable(vector<int> &A) {
    int N = A.size();
    vector<int> B = A;
    sort(B.begin(), B.end());

    for (int i = 0; i < N / 2; ++i) {
        int a1 = A[i], a2 = A[N - 1 - i];
        int b1 = B[i], b2 = B[N - 1 - i];
        // Nếu không thể hoán đổi a1, a2 thành b1, b2 theo mọi cách hoán vị
        if (!((a1 == b1 && a2 == b2) || (a1 == b2 && a2 == b1))) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        cout << (isSortable(A) ? "Yes" : "No") << "\n";
    }
    return 0;
}
