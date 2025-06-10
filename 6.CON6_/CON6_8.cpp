#include <bits/stdc++.h>
using namespace std;

int countPairs(int x, const vector<int>& Y, const set<int>& ySet) {
    /*
    x = 0 -> ko có y => 0 cách
    x = 1 -> y = 0 => 1 cách
    x = 2 -> y = 0,1 + 5,6,7,...(trừ trường hợp y = 3 và y = 4)
    x = 3 -> y = 0,1,2 + 4,5,6,...(chỉ cần y lớn hơn x)
    x >= 4 -> y = 0,1 + x+1,x+2,...
    */
    if (x == 0) return 0;
    if (x == 1) return ySet.count(0);  // chỉ y = 0 thỏa mãn với x = 1

    // Số y sao cho y > x
    int idx = upper_bound(Y.begin(), Y.end(), x) - Y.begin();
    int count = Y.size() - idx;

    // Thêm y = 0 và y = 1 vì luôn thỏa mãn x^y > y^x với x > 1
    count += ySet.count(0) + ySet.count(1);

    // Trừ các trường hợp đặc biệt với x = 2
    if (x == 2) {
        count -= ySet.count(3) + ySet.count(4);
    }

    return count;
}

int main() {
    int T; 
    cin >> T;
    while (T--) {
        int n, m; 
        cin >> n >> m;
        vector<int> X(n), Y(m);
        for (int& x : X) cin >> x;
        for (int& y : Y) cin >> y;

        sort(Y.begin(), Y.end());
        set<int> ySet(Y.begin(), Y.end());  // giữ các phần tử duy nhất

        long long total = 0;
        for (int x : X) {
            total += countPairs(x, Y, ySet);
        }

        cout << total << endl;
    }
    return 0;
}
