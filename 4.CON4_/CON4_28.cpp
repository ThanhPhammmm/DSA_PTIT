#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long N;
        cin>>N;
        vector<long long> A(N);
        for(int i = 0;i < N;i++){
            cin>>A[i];
        }

        sort(A.begin(), A.end());

        int small = 0;
        int big = N / 2;
        int res = N;

        while(big < N && small < N / 2){
            if(A[big] >= 2 * A[small]){
                res -= 1;
                big += 1;
                small += 1;
            }
            else{
                big += 1;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}

