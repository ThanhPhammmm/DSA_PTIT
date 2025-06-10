#include <bits/stdc++.h>
using namespace std;

int ways = 0;

void countWays(int n){
    if(n == 0){
        ways += 1;
        return;
    }
    for(int i = 1;i <= 3;i++){
        if(n - i >= 0){
            countWays(n - i);
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        ways = 0;
        countWays(n);
        cout<<ways<<endl;
    }
}