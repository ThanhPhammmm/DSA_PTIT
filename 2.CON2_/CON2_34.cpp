/*X*/
#include <bits/stdc++.h>
using namespace std;

int board[8][8];
bool col[8], diag1[15], diag2[15];
int maxScore;

void Try(int row, int currentScore) {
    if (row == 8) {
        maxScore = max(maxScore, currentScore);
        return;
    }

    for (int c = 0; c < 8; ++c) {
        if (!col[c] && !diag1[row - c + 7] && !diag2[row + c]) {
            col[c] = diag1[row - c + 7] = diag2[row + c] = true;
            Try(row + 1, currentScore + board[row][c]);
            col[c] = diag1[row - c + 7] = diag2[row + c] = false;
        }
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                cin >> board[i][j];

        maxScore = 0;
        memset(col, false, sizeof(col));
        memset(diag1, false, sizeof(diag1));
        memset(diag2, false, sizeof(diag2));

        Try(0, 0);
        cout << maxScore << '\n';
    }
    return 0;
}
