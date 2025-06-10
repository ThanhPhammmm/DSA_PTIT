#include <bits/stdc++.h>
using namespace std;

int countWays(string s) {
    int n = s.length();
    if (s[0] == '0') return 0;

    vector<int> dp(n + 1, 0);
    dp[0] = 1; // chuỗi rỗng
    dp[1] = 1; // chỉ 1 ký tự đầu (đảm bảo s[0] != '0'  )

    for(int i = 2;i <= n;i++){
        if(s[i - 1] != '0'){
            dp[i] += dp[i - 1];
        }
        int twoDigit = stoi(s.substr(i - 2, 2));
        if(twoDigit >= 10 && twoDigit <= 26){
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << countWays(s) << endl;
    }
    return 0;
}
