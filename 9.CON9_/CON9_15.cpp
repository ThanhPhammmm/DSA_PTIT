/*Done*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> used;

void DFS(int num){
    used[num] = 1;

    for(int i = 0;i < edges[num].size();i++){
        if(!used[edges[num][i]]){
            DFS(edges[num][i]);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int v, e;
        cin>>v>>e;
        edges.resize(v + 1);
        used.resize(e + 1);

        while(e--){
            int x, y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        int result_count = 0;

        for(int i = 1;i <= v;i++){
            if(!used[i]){
                result_count += 1;
                DFS(i);
            }
        }
        cout<<result_count<<endl;
    }
}