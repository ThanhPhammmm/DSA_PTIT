/*Done*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

map<int, Node*> nodeMap;

// Hàm xây dựng cây từ các cạnh
Node* buildTree(int n) {
    nodeMap.clear();
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int u, v;
        char dir;
        cin >> u >> v >> dir;

        if (!nodeMap[u]) nodeMap[u] = new Node(u);
        if (!nodeMap[v]) nodeMap[v] = new Node(v);

        if (dir == 'L')
            nodeMap[u]->left = nodeMap[v];
        else
            nodeMap[u]->right = nodeMap[v];

        if (i == 0)
            root = nodeMap[u];  // node đầu tiên là gốc
    }
    return root;
}

// Hàm duyệt cây level-order
void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->data << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        Node* root = buildTree(N);
        levelOrder(root);
    }
    return 0;
}
