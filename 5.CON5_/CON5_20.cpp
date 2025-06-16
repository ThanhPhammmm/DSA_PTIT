/*Done*/
/*Hoc thuoc*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sumSubstrings(string s) {
    int n = s.size();
    ll res = 0, prev = 0;

    for (int i = 0; i < n; i++) {
        int num = s[i] - '0';
        prev = 10 * prev + (i + 1) * num;
        res += prev;
    }

    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << sumSubstrings(s) << endl;
    }
    return 0;
}
