/*Done*/
#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(const string& s) {
    stack<int> st;
    st.push(-1); // mốc ban đầu
    int maxLen = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } 
        else {
            st.pop();
            if (st.empty()) {
                st.push(i); // cập nhật mốc mới
            } 
            else {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }

    return maxLen;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin>>s;
        cout << longestValidParentheses(s) << endl;
    }

    return 0;
}
