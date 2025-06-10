#include <bits/stdc++.h>
using namespace std;

void next_permutation(string &s) {
    int n = s.length(), i = n - 2;
    
    // Tìm vị trí đầu tiên mà s[i] < s[i+1]
    while (i >= 0 && s[i] >= s[i + 1]) i--;
    
    if (i < 0) {
        cout << "BIGGEST";
        return;
    }

    // Tìm phần tử nhỏ nhất bên phải i nhưng lớn hơn s[i]
    int j = n - 1;
    while (s[j] <= s[i]) j--;

    swap(s[i], s[j]);    // Hoán đổi
    reverse(s.begin() + i + 1, s.end()); // Đảo ngược phần sau i
    
    cout << s;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Bỏ dòng xuống dòng sau số test

    while (t--) {
        int test_id;
        string s;
        cin >> test_id >> s;
        
        cout << test_id << " ";
        next_permutation(s);
        cout << endl;
    }

    return 0;
}
