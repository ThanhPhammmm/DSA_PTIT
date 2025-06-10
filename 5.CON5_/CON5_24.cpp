#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n, m;
        cin>>n>>m;

        long long A[n + 5][m + 5];

        for(int i = 0;i <= n;i++){
            A[i][0] = 1;
        }

        for(int j = 0;j <= m;j++){
            A[0][j] = 1;
        }

        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                A[i][j] = A[i - 1][j] + A[i][j - 1];
            }
        }

        cout<<A[n][m]<<endl;
    }
}
