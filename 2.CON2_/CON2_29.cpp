/*Done*/
#include <bits/stdc++.h>
using namespace std;

int m, n;
int res = 0;

void Try(vector<vector<int>> &a, int row, int column){
    if(a[row][column] == a[m - 1][n - 1]){
        res += 1;
        return;
    }
    if(row < m - 1) Try(a, row + 1, column);
    if(column < n - 1) Try(a, row, column + 1);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>m>>n;
        vector<vector<int>> a(m, vector<int>(n));
        res = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                cin>>a[i][j];
            }
        }
        Try(a, 0, 0);
        cout<<res<<endl;
    }
}
