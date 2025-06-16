/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for (int &x : A) cin >> x;

        sort(A.begin(), A.end());
        int count = 0, j = 0;

        for (int i = 0; i < n; ++i) {
            for(int j = i + 1;j < n;j++){
                if(A[j] - A[i] < k){
                    count += 1;
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}
