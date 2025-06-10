#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int K;
        string S;
        cin >> K >> S;

        unordered_map<char, int> freq;
        for (char c : S) {
            freq[c]++;
        }

        priority_queue<int> pq;
        for (auto it : freq) {
            pq.push(it.second);
        }

        while (K-- && !pq.empty()) {
            int top = pq.top(); 
            pq.pop();
            top--;
            if (top > 0) pq.push(top);
        }

        long long result = 0;
        while (!pq.empty()) {
            long long f = pq.top(); 
            pq.pop();
            result += f * f;
        }

        cout << result << "\n";
    }
    return 0;
}
