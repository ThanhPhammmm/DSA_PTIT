#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;

int modExp(long long N, long long K){
    int res = 1;
    N = N % MOD;
    while(K > 0){
        if(K % 2 == 1){
            res = (res * N)% MOD;
        }
        N = (N * N) % MOD;
        K /= 2;
    }
    return res;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        long long N, K;
        cin>>N>>K;
        int result = modExp(N, K);
        cout<<result<<endl;
    }
}