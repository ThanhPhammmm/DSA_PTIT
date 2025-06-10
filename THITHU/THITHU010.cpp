#include <iostream>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent;
public:
    DSU(int n) : parent(n + 1) {
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unionSet(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false; // cycle
        parent[pv] = pu;
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges(n, vector<int>(2));
        vector<int> parent(n + 1, 0);
        vector<int> cand1, cand2;
        for (int i = 0; i < n; ++i) {
            cin >> edges[i][0] >> edges[i][1];
        }

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (parent[v] == 0)
                parent[v] = u;
            else {
                cand1 = {parent[v], v};  // cạnh đầu tiên vào v
                cand2 = {u, v};          // cạnh thứ hai vào v
                break;
            }
        }

        DSU dsu(n);
        for (const auto& edge : edges) {
            if (edge == cand2) continue; // giả sử bỏ cand2
            if (!dsu.unionSet(edge[0], edge[1])) {
                // cycle xuất hiện
                if (!cand1.empty()) {
                    cout << cand1[0] << " " << cand1[1] << "\n";
                } else {
                    cout << edge[0] << " " << edge[1] << "\n";
                }
                goto next;
            }
        }

        // không có chu trình → bỏ cand2 là đúng
        cout << cand2[0] << " " << cand2[1] << "\n";
        next:;
    }

    return 0;
}
