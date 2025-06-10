#include <bits/stdc++.h>
using namespace std;

int getNthUgly(int n) {
    vector<int> ugly(n);

    ugly[0] = 1;

    int next2 = 2;
    int next3 = 3;
    int next5 = 5;

    int i2 = 0;
    int i3 = 0;
    int i5 = 0;

    for(int i = 1;i < n;i++){
        int next = min({next2,next3,next5});
        ugly[i] = next;
        if(next == next2){
            i2 += 1;
            next2 = ugly[i2] * 2;
        }
        if(next == next3){
            i3 += 1;
            next3 = ugly[i3] * 3;
        }
        if(next == next5){
            i5 += 1;
            next5 = ugly[i5] * 5;
        }
    }
    return ugly[n - 1];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << getNthUgly(N) << endl;
    }
    return 0;
}
