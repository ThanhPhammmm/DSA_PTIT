/*Done*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> root(10000, 0);

int findRoot(int num){
    if(root[num] == num){
        return num;
    }
    return findRoot(root[num]);
}

int unionSet(int x, int y){
    int u = findRoot(x);
    int v = findRoot(y);

    if(u == v){
        return 1;
    }
    root[v] = u;
    return false;
}
int main() {
    int t;
    cin>>t;
    while (t--){
        int v, e;
        cin>>v>>e;

        for(int i = 1;i <= v;i++){
            root[i] = i;
        }

        int cycle = 0;

        while(e--){
            int x, y;
            cin>>x>>y;

            if(unionSet(x,y)){
                cycle = 1;
            }
        }
        if(cycle) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
}
