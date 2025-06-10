#include <bits/stdc++.h>
using namespace std;

int N;
int constPrice[16][16];
int dp[1 << 15][15];

int TSP(int mask, int u){
    if(mask == ((1 << N) - 1)){
        return constPrice[u][0];
    }
    if(dp[mask][u] != -1){
        return dp[mask][u];
    }

    int ans = INT_MAX;

    for(int v = 0;v < N;v++){
        if(!(mask & (1 << v)) && constPrice[u][v] != 0){
            int nextConst = TSP(mask | (1 << v), v);
            ans = min(ans, constPrice[u][v] + nextConst);
        }
    }

    return dp[mask][u] = ans;
}
int main(){
    cin>>N;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin>>constPrice[i][j];
        }
    }

    for(int i = 0;i < (1 << N);i++){
        for(int j = 0;j < N;j++){
            dp[i][j] = -1;
        }
    }

    int result = TSP(1, 0);
    cout<<result<<endl;
}