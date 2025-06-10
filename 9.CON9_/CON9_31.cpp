#include <bits/stdc++.h>
using namespace std;

/*
A situation when a graph can not be formed with all the existed vertexes is that when there is a vertex which connects its self.
*/
int cycle = 0;
vector<vector<int>> edges;
vector<int> used;

void DFS(int vertex, int parent){
  used[vertex] = 1;
  for(int i = 0;i < edges[vertex].size();i++){
    if(!used[edges[vertex][i]]){
      DFS(edges[vertex][i], vertex);
    }
    else if(used[edges[vertex][i]] && edges[vertex][i] != parent){
      cycle = 1;
    }
  }
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int n_temp = n;
    edges.resize(1005);
    used.resize(1005);
    n--;
    while(n--){
      int x, y;
      cin>>x>>y;
      edges[x].push_back(y);
      edges[y].push_back(x);
    }

    DFS(1, -1);
    for(int i=1;i<=n_temp;i++){
      if(!used[i]){
      	cycle = 1;
      }
    }
    if(cycle){
      cout<<"NO\n";
    }
    else{
      cout<<"YES\n";
    }
      edges.clear();
      used.clear();
      cycle = 0;
  }
}