#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    queue<int> q;
    string command;
    
    while (Q--) {
        cin >> command;
        if (command == "PUSH") {
            int x;
            cin >> x;
            q.push(x);
        } 
        else if (command == "PRINTFRONT") {
            if (q.empty()) {
                cout << "NONE" << endl;
            } else {
                cout << q.front() << endl;
            }
        } 
        else if (command == "POP") {
            if (!q.empty()) {
                q.pop();
            }
        }
    }
    return 0;
}
