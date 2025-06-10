#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;
    
    // Vì n <= 100 => tạo mảng catalan đến 100 luôn
    vector<ll> catalan(101, 0);
    catalan[0] = 1;
    
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }
    
    while (T--) {
        int n;
        cin >> n;
        cout << catalan[n] << endl;
    }
    
    return 0;
}
