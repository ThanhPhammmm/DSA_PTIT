/*
-Từ map<int,int> có thể quy ra được pair<int,int>
-
*/
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second != b.second)
        return a.second > b.second; // Tần suất giảm dần
    return a.first < b.first;       // Nếu bằng thì số nhỏ hơn trước
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        vector<pair<int, int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), cmp);

        for (auto p : v) {
            for (int i = 0; i < p.second; i++) {
                cout << p.first << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
