#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    for(int i = 0;i < (1 << n);i++){
        for(int j = n - 1;j >= 0;j--){
            cout<<((i & (1 << j)) ?'B' : 'A');
        }
        cout<<" ";
    }
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

// Số thập phân	    Dạng nhị phân	    Xâu AB
// 0		            000                 AAA
// 1	                001	                AAB
// 2	                010	                ABA
// 3	                011	                ABB
// 4	                100	                BAA
// 5	                101	                BAB
// 6	                110	                BBA
// 7	                111	                BBB