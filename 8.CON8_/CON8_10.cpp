#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        queue<pair<int ,int>> q;
        q.push({n, 0});

        while(1){
            auto [value, ways] = q.front();
            q.pop();
            if(value == 1){
                cout<<ways<<endl;
                break;
            }
            for(int i = 2;i <= sqrt(value);i++){
                if(value % i == 0){
                    int maxN  = max(i, value / i);
                    q.push({maxN, ways + 1});
                }
            }
            if(value - 1 >= 0){
                q.push({value - 1, ways + 1});
            }
        }

    }
}