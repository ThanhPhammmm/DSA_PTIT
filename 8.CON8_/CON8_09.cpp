/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, T;
        cin>>S>>T;
        queue<pair<int ,int>> q;
        q.push({S, 0});

        while(1){
            auto [value, ways] = q.front();
            q.pop();
            if(value == T){
                cout<<ways<<endl;
                break;
            }
            if(value * 2 > 0){
                q.push({value * 2, ways + 1});
            }
            if(value - 1 >= 0){
                q.push({value - 1, ways + 1});
            }
        }
    }
}