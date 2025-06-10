/*Done*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> edges(100);
vector<int> used(100, 0);

void BFS(int u){
    queue<int> q;
    q.push(u);
    used[u] = 1;
    while(q.size() > 0){
        u = q.front();
        cout<<u<<" ";
        q.pop();
        for(int num : edges[u]){
            if(!used[num]){
                q.push(num);
                used[num] = 1;
            }
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
            edges[y].push_back(x);
        }

        BFS(u);
        cout<<endl;

        for(int i = 0;i < 100;i++){
            edges.clear();
            used[i] = 0;
        }
    }
}