/*Done*/
#include <bits/stdc++.h>
using namespace std;

void solvePolynomial(vector<int>& P, vector<int>& Q, int m, int n){
    vector<int> R((m - 1 + n - 1) + 1, 0);

    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            R[i + j] += P[i] * Q[j];
        }
    }
    for(int num : R){
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int m ,n;
        cin>>m>>n;

        vector<int> P(m);
        vector<int> Q(n);

        for(int i = 0;i < m;i++){
            cin>>P[i];
        }
        for(int j = 0;j < n;j++){
            cin>>Q[j];
        }

        solvePolynomial(P, Q, m , n);
    }
}