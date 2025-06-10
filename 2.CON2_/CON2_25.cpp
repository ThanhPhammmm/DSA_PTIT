#include <bits/stdc++.h>
using namespace std;

int sum = 0;
int N;
int A[105];
int k;
bool ok = false;

void backtracking(int prev, int sum){
    if(ok){
        return;
    }
    for(int i = prev;i <= N;i++){
        if(sum + A[i] <= k){
            if(sum + A[i] == k){
                ok = true;
            }
            else{
                backtracking(i + 1, sum + A[i]);
            }
        }

    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        sum = 0;
        for(int i = 0;i < N;i++){
            cin>>A[i];
            sum += A[i];
        }
        if(sum % 2 == 0){
            k = sum / 2;
            backtracking(0, 0);
            if(ok){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            cout<<"NO\n";
        }

    }
}
