#include <bits/stdc++.h>
using namespace std;

int findElement(int N, int K){
    while(N > 1){
        int mid = (1 << (N - 1)) - 1;

        if(K == mid + 1){
            return N;
        }
        if(K < (mid + 1)){
            N--;
        }
        else{
            K = (1 << N) - K;
            N--;
        }
    }
    return 1;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N, K;
        cin>>N>>K;
        cout<<findElement(N, K)<<endl;
    }
}