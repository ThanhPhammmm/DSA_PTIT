#include <bits/stdc++.h>
using namespace std;

int countSet = 0;

void countSubset(int start, int n, int k, int s, int sum){
    if(k == 0){
        if(s == sum){
            countSet += 1;
        }
        return;
    }
    for(int i = start;i <= n;i++){
        if((sum + i) > s){
            return;
        }
        countSubset(i + 1, n, k - 1, s, sum + i);
    }
}
int main(){
    int n, k ,s;
    while(1){
        cin>>n>>k>>s;
        if(n == 0 && k == 0 && s == 0){
            break;
        }
        countSet = 0;
        countSubset(1, n, k ,s, 0);
        cout<<countSet<<endl;
    }
}