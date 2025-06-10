#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int v, e;
        cin>>v>>e;
        vector<set<int>> edges(v + 1);

        while(e--){
            int x, y;
            cin>>x>>y;
            edges[x].insert(y);
        }

        for(int i = 1;i <= v;i++){
            cout<<i<<": ";
            for(int num : edges[i]){
                cout<<num<<" ";
            }
            cout<<endl;
        }
    }
}