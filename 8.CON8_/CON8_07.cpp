/*Done*/
#include <bits/stdc++.h>
using namespace std;

long long countBDN(long long n){
    queue<long long> q;
    q.push(1);
    int ans = 0;
    while(q.size()){
        long long num = q.front();
        q.pop();
        if(num > n){
            break;
        }
        ans += 1;
        q.push(num * 10);
        q.push(num * 10 + 1);
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        cout<<countBDN(n)<<endl;
    }
}
