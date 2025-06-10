/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        queue<long long> q;
        q.push(1);
        while(1){
            int num = q.front();
            q.pop();
            if(num % n == 0){
                cout<<num<<endl;
                break;
            }
            else{
                q.push(num * 10);
                q.push(num * 10 + 1);
            }
        }
    }
}