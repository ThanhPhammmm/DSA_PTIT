/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<vector<int>> edges(n + 1, vector(n + 1, 0));

    for(int i = 1;i <= n;i++){
        int x, y;
        cin>>x>>y;
        edges[i][x] = 1;
        edges[i][y] = 1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(edges[i][j]){
                cout<<1<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }

}