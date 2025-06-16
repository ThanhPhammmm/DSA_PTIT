#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1005;
int parent[MAX];

int find(int u) {
    if (parent[u] == u)
        return u;  // Path compression
    return find(parent[u]);
}

bool unionSet(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return true;  // Cycle detected
    parent[pv] = pu;
    return false;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;
        
        // Khởi tạo DSU
        for (int i = 1; i <= V; ++i)
            parent[i] = i;
        
        bool hasCycle = false;
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            if (unionSet(u, v))
                hasCycle = true;
        }

        cout << (hasCycle ? "YES" : "NO") << endl;
    }
    return 0;
}
