#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> used;
vector<int> trace;

void findPath(int s, int d){
    if(!trace[d]){
        cout<<-1<<endl;
        return;
    }
    vector<int> res;
    while(s != d){
        res.push_back(d);
        d = trace[d];
    }
    res.push_back(d);
    reverse(res.begin(), res.end());
    for(int num : res){
        cout<<num<<" ";
    }
    cout<<endl;
}
void DFS(int num){
    if(used[num]){
        return;
    }

    used[num] = 1;

    for(int i = 0;i < edges[num].size();i++){
        if(!used[edges[num][i]]){
            trace[edges[num][i]] = num;
            DFS(edges[num][i]);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int v, e, s, d;
        cin>>v>>e>>s>>d;

        edges.resize(v + 1);
        used.resize(v + 1, 0);
        trace.resize(v + 1, 0);

        while(e--){
            int x, y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        
        DFS(s);
        findPath(s, d);
    }
}