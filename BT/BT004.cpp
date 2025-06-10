#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

const int INF = INT_MAX;
const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int knightMinPath(const vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
    int N = grid.size();
    vector<vector<int>> dist(N, vector<int>(N, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    dist[x1][y1] = grid[x1][y1];
    pq.push({dist[x1][y1], x1, y1});

    while (!pq.empty()) {
        auto [cost, x, y] = pq.top(); pq.pop();
        if (x == x2 && y == y2) return cost;

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                int new_cost = cost + grid[nx][ny];
                if (new_cost < dist[nx][ny]) {
                    dist[nx][ny] = new_cost;
                    pq.push({new_cost, nx, ny});
                }
            }
        }
    }

    return -1; // không đến được
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> grid(N, vector<int>(N));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> grid[i][j];

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // Chuyển từ 1-based sang 0-based
        x1--; y1--; x2--; y2--;

        cout << knightMinPath(grid, x1, y1, x2, y2) << "\n";
    }
    return 0;
}
