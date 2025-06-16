/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        set<char> digits;
        while (n--) {
            string num;
            cin >> num;
            for (char c : num) {
                digits.insert(c);
            }
        }

        for (char d : digits) {
            cout << d << " ";
        }
        cout << endl;
    }
    return 0;
}
