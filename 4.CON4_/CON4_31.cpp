#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
long long N, K;

vector<vector<long long>> multiply(vector<vector<long long>> &A, vector<vector<long long>> &B){
    vector<vector<long long>> C(N, vector<long long>(N, 0));

    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            for(int k = 0;k < N;k++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}
vector<vector<long long>> maxtrixPow(vector<vector<long long>> &A, int K){

    vector<vector<long long>> res(N, vector<long long>(N ,0));

    for(int i = 0;i < N;i++){
        res[i][i] = 1;
    }

    while(K > 0){
        if(K % 2 == 1){
            res = multiply(res, A);
        }
        A = multiply(A, A);
        K /= 2;
    }
    return res;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>N>>K;

        vector<vector<long long>> A(N, vector<long long>(N, 0));

        for(int i = 0;i < N;i++){
            for(int j = 0;j< N;j++){
                cin>>A[i][j];
            }
        }

        vector<vector<long long>> result = maxtrixPow(A, K);

        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}