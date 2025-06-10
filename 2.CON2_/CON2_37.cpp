#include <bits/stdc++.h>
using namespace std;

int maxLen = 0;
vector<vector<int>> adj;
vector<vector<bool>> visitedEdges;

void dfs(int u, int length){
    maxLen = max(maxLen, length);

    for(int v : adj[u]){
        if(visitedEdges[u][v] == false){
            visitedEdges[u][v] = true;
            visitedEdges[v][u] = true;

            dfs(v, length + 1);

            /*Backtracking*/
            visitedEdges[u][v] = false;
            visitedEdges[v][u] = false;
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N, M;
        cin>>N>>M;
        
        adj.assign(N, vector<int>());

        visitedEdges.assign(N, vector<bool>(N, false));

        for(int i = 0;i < M;i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        maxLen = 0;

        for(int i = 0;i < N;i++){
            dfs(i, 0);
        }

        cout<<maxLen<<endl;
    }
}