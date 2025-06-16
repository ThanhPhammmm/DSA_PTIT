/*Done*/
/*
Nếu một ký tự có số lần xuất hiện lớn hơn (n + 1) / 2 (trong đó n là độ dài chuỗi), 
thì không thể sắp xếp lại được sao cho không có hai ký tự giống nhau kề nhau.
*/
#include <bits/stdc++.h>
using namespace std;

int canRearrange(string s) {
    int n = s.size();
    vector<int> freq(26, 0);

    for (char c : s) {
        freq[c - 'a']++;
    }

    int maxFreq = *max_element(freq.begin(), freq.end());

    // Kiểm tra điều kiện
    if (maxFreq <= (n + 1) / 2)
        return 1;
    else
        return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin>>s;
        cout << canRearrange(s) << endl;
    }
}
