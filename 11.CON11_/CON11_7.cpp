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

// Tạo cây từ danh sách cạnh
Node* buildTree(int n) {
    nodeMap.clear();
    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int u, v;
        char dir;
        cin >> u >> v >> dir;

        if (nodeMap.find(u) == nodeMap.end()) {
            nodeMap[u] = new Node(u);
        }
        if (nodeMap.find(v) == nodeMap.end()) {
            nodeMap[v] = new Node(v);
        }

        if (dir == 'L') {
            nodeMap[u]->left = nodeMap[v];
        } else {
            nodeMap[u]->right = nodeMap[v];
        }

        if (!root) root = nodeMap[u]; // chọn node đầu tiên làm root
    }
    return root;
}

// Duyệt theo kiểu zigzag / spiral
void spiralOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    bool leftToRight = false;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; ++i) {
            Node* node = q.front(); q.pop();

            int index = leftToRight ? i : size - 1 - i;
            level[index] = node->data;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        for (int val : level) cout << val << " ";
        leftToRight = !leftToRight;
    }
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        Node* root = buildTree(N);
        spiralOrder(root);
    }
    return 0;
}
