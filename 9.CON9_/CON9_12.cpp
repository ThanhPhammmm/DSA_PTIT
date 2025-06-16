/*Done*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> edges(100);
vector<int> used(100, 0);
vector<int> trace(100, 0);

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
void BFS(int num){
    if(used[num]){
        return;
    }
    used[num] = 1;

    queue<int> q;
    q.push(num);
    while(q.size()){
        int tmp_num = q.front();
        for(int i = 0;i < edges[tmp_num].size();i++){
            if(!used[edges[tmp_num][i]]){
                q.push(edges[tmp_num][i]);
                used[edges[tmp_num][i]] = 1;
                trace[edges[tmp_num][i]] = tmp_num;
            }
        }
        q.pop();
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int v, e, s, d;
        cin>>v>>e>>s>>d;

        while(e--){
            int x, y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        
        BFS(s);
        findPath(s, d);
    }
}