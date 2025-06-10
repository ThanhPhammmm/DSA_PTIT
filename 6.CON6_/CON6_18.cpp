#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> A(n), B(m);

        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < m; i++) cin >> B[i];

        vector<int> C;

        C.insert(C.end(), A.begin(), A.end());
        C.insert(C.end(), B.begin(), B.end());

        sort(C.begin(), C.end());

        for (int num : C) cout << num << " ";
        cout << endl;
    }
    return 0;
}
