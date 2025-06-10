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
        if (parent[x] != x) parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unionSet(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return false; // same root => cycle
        parent[pa] = pb;
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; // n edges, n nodes
        cin >> n;
        vector<vector<int>> edges(n, vector<int>(2));
        for (int i = 0; i < n; ++i)
            cin >> edges[i][0] >> edges[i][1];

        DSU dsu(n);
        vector<int> result;

        for (const auto& edge : edges) {
            if (!dsu.unionSet(edge[0], edge[1])) {
                result = edge; // this edge creates cycle
            }
        }

        cout << result[0] << " " << result[1] << "\n";
    }
    return 0;
}
