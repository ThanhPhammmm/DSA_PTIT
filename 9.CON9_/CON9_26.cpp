#include<bits/stdc++.h>
using namespace std;

int root[1001];

int findRoot(int x){
    if(x == root[x]){
        return x;
    }
    return findRoot(root[x]);
}

bool unionSet(vector<pair<int, int>> &edges){
    for(auto [x, y] : edges){
        int u = findRoot(x);
        int v = findRoot(y);
        if(u == v){
            return 1;
        }
        root[v] = u;
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int v, e;
        cin>>v>>e;
        for(int i = 1;i <= v;i++){
            root[i] = i;
        }
        vector<pair<int, int>> edges;

        while(e--){
            int x, y;
            cin>>x>>y;
            edges.push_back({x, y});
        }

        if(unionSet(edges)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
}