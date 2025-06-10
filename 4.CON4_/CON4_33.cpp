#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;

long long reverseNumber(long long N){
    long long result = 0;
    while(N > 0){
        result = 10 * result + N % 10;
        N /= 10;
    }
    return result;
}

long long modExp(long long N, long long R){
    long long result = 1;
    N = N % MOD;
    while(R > 0){
        if(R % 2 == 1){
            result = (result * N) % MOD;
        }
        N = (N * N) % MOD;
        R /= 2;
    }
    return result;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        long long N;
        cin>>N;

        long long R = reverseNumber(N);
        long long result = modExp(N, R);
        cout<<result<<endl;
    }
}