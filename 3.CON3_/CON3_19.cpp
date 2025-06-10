#include <bits/stdc++.h>
using namespace std;

void solve(long long P, long long Q){
    while(1){
        if(Q % P == 0){
            cout<<"1/"<<Q / P<<endl;
            return;
        }
        long long X = (Q / P) + 1;
        cout<<"1/"<<X<<" + ";
        P = P * X - Q;
        Q = Q * X;
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        long long P,Q;
        cin>>P>>Q;
        solve(P, Q);
    }
}