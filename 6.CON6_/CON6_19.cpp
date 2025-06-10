#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        set<int> s;
        int x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            s.insert(x);  // chỉ giữ giá trị duy nhất
        }

        int minA = *s.begin();
        int maxA = *s.rbegin();
        int need = maxA - minA + 1 - s.size();
        cout << need << endl;
    }
    return 0;
}
