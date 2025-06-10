#include <bits/stdc++.h>
using namespace std;
void solvePolynomial(vector<long long> &P, vector<long long> &Q){
    long long size_of_P =P.size();
    long long size_of_Q = Q.size();
        
    vector<long long> R(size_of_P + size_of_Q - 1, 0);

    for(long long i = 0;i < size_of_P;i++){
        for(long long j = 0;j < size_of_Q;j++){
            R[i + j] += P[i] * Q[j];
        }
    }

    for(long long k = 0;k < R.size();k++){
        cout<<R[k]<<" ";
    }
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        long long M, N;
        cin>>M>>N;
        vector<long long> P(M) ,Q(N);
        for(long long i = 0;i < M;i++){
            cin>>P[i];
        }
        for(long long j = 0;j < N;j++){
            cin>>Q[j];
        }
        solvePolynomial(P, Q);
    }
}