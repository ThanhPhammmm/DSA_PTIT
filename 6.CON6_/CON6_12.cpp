/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) cin >> A[i];

        // Sắp xếp giảm dần
        sort(A.begin(), A.end(), greater<int>());

        // In ra k phần tử lớn nhất
        for (int i = 0; i < k; ++i) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
