#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 1e7 + 5;
long long A[MAXN];
long long B[MAXN];

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;

        for(int i = 0;i < N;i++){
            cin>>A[i];
        }
        for(int j = 0;j < (N - 1);j++){
            cin>>B[j];
        }

        int index;

        for(int k = 0;k < N - 1;k++){
            if(A[k] != B[k]){
                index = k + 1;
                break;
            }
        }
        cout<<index<<endl;
    }
}