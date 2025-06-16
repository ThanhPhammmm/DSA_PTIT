/*Done*/
#include <bits/stdc++.h>
using namespace std;

/*
--Có hướng--
Chu trình Euler: Mọi đỉnh của đồ thị đều có bán bậc ra bằng bán bậc vào
*/

int main(){
    int t;
    cin>>t;
    while(t--){
        int v, e;
        cin>>v>>e;
        vector<int> in(v + 1, 0);
        vector<int> out(v + 1, 0);
        while(e--){
            int u, v;
            cin>>u>>v;
            out[u]++;
            in[v]++;
        }

        int ok = 1;

        for(int i = 1;i <= v;i++){
            if(in[i] != out[i]){
                ok = 0;
                break;
            }
        }
        if(ok){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}
