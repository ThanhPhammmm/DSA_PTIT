/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<vector<int>> edges(n + 1, vector<int>(n + 1));

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin>>edges[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(edges[i][j] == 1){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}
