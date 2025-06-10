/*Done*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> edges(100);
vector<int> used(100, 0);

void DFS(int u){
    cout<<u<<" ";
    used[u] = 1;
    for(int i = 0;i < edges[u].size();i++){
        if(used[edges[u][i]] != 1){
            DFS(edges[u][i]);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int v, e, u;
        cin>>v>>e>>u;
        while(e--){
            int x, y;
            cin>>x>>y;
            edges[x].push_back(y);
        }

        DFS(u);
        cout<<endl;

        for(int i = 0;i < 100;i++){
            edges.clear();
            used[i] = 0;
        }
    }
}