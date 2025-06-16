#include <bits/stdc++.h>
using namespace std;

/*
-clear function will delete all the current components of vector, as well as its size.
->if we do not resize this vector, it will be a blank vector, with no size.
*/

/*
-resize function is used when we wanna to decide which size of this vector being used.
*/

/*
-assign function is used when we wanna to assign a specific value for the vector's components.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges(100);
vector<int> used(100);

void DFS(int num){
    if(used[num]) return;

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
        int n, m;
        cin>>n>>m;

        while(m--){
            int u, v;
            cin>>u>>v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        int q;
        cin>>q;

        while(q--){
            int x, y;
            cin>>x>>y;
            DFS(x);
            if(used[y]){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
            used.assign(100, 0);

        }
    }
}