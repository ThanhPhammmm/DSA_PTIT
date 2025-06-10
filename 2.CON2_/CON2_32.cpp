/*X*/
#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra biểu thức có hợp lệ hay không
bool isValid(string s) {
    int count = 0;
    for (char c : s) {
        if (c == '(') count++;
        else if (c == ')') {
            count--;
            if (count < 0) return false;
        }
    }
    return count == 0;
}

// Hàm xử lý từng test
vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> visited;
    queue<string> q;
    vector<string> res;
    bool found = false;

    q.push(s);
    visited.insert(s);

    while (!q.empty()) {
        string curr = q.front(); q.pop();

        if (isValid(curr)) {
            res.push_back(curr);
            found = true;
        }

        if (found) continue; // Dừng nếu đã tìm được biểu thức hợp lệ

        for (int i = 0; i < curr.size(); ++i) {
            if (curr[i] != '(' && curr[i] != ')') continue;
            string next = curr.substr(0, i) + curr.substr(i + 1);
            if (!visited.count(next)) {
                visited.insert(next);
                q.push(next);
            }
        }
    }

    if (res.empty()) return {"-1"};
    sort(res.begin(), res.end()); // Sắp xếp theo từ điển
    return res;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // bỏ dòng trống sau số T

    while (T--) {
        string s;
        getline(cin, s);
        vector<string> ans = removeInvalidParentheses(s);
        for (string str : ans) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
