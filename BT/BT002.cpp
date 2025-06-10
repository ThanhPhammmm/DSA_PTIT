#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int dx[] = {-1, 1, 0, 0}; // trái, phải
int dy[] = {0, 0, -1, 1}; // lên, xuống

int dijkstra(const vector<vector<int>> &A, int x1, int y1, int x2, int y2) {
    int M = A.size(), N = A[0].size();
    vector<vector<int>> dist(M, vector<int>(N, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    dist[x1][y1] = A[x1][y1];
    pq.push({dist[x1][y1], x1, y1});

    while (!pq.empty()) {
        auto [d, x, y] = pq.top(); pq.pop();
        if (x == x2 && y == y2) return d;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                int nd = d + A[nx][ny];
                if (nd < dist[nx][ny]) {
                    dist[nx][ny] = nd;
                    pq.push({nd, nx, ny});
                }
            }
        }
    }

    return dist[x2][y2];
}

int main() {
    int t; cin >> t;
    while (t--) {
        int M, N; cin >> M >> N;
        vector<vector<int>> A(M, vector<int>(N));
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                cin >> A[i][j];

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // chuyển về chỉ số mảng (0-indexed)
        x1--; y1--; x2--; y2--;

        cout << dijkstra(A, x1, y1, x2, y2) << "\n";
    }

    return 0;
}
