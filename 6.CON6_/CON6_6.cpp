/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        int count0 = 0, count1 = 0, count2 = 0;
        int x;

        // Đếm số lượng 0, 1, 2
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x == 0) count0++;
            else if (x == 1) count1++;
            else count2++;
        }

        // In ra kết quả
        for (int i = 0; i < count0; i++) cout << "0 ";
        for (int i = 0; i < count1; i++) cout << "1 ";
        for (int i = 0; i < count2; i++) cout << "2 ";
        cout << endl;
    }

    return 0;
}
