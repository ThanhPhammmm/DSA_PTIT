#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; 
    cin >> T;
    while (T--) {
        int n, x;
        cin>>n>>x;
        vector<int> A(n);

        for (int i = 0; i < n; ++i){
            cin >> A[i];
        }

        // Bubble sort theo |A[i] - x| (ổn định)
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                int d1 = abs(A[j] - x);
                int d2 = abs(A[j + 1] - x);
                if (d1 > d2) {
                    swap(A[j], A[j + 1]);
                }
            }
        }

        for (int i = 0; i < n; ++i)
            cout << A[i] << " ";
        cout << endl;
    }
    return 0;
}
