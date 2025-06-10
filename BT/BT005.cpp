#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LCS_Length(const string& A, const string& B) {
    int m = A.size(), n = B.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    return dp[m][n];
}

int shortestCommonSupersequenceLength(const string& A, const string& B) {
    return A.size() + B.size() - LCS_Length(A, B);
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string A, B;
        cin >> A >> B;
        cout << shortestCommonSupersequenceLength(A, B) << '\n';
    }
    return 0;
}
