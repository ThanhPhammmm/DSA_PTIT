#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        long long N, K;
        cin>>N>>K;
        long long length[N + 1];
        length[1] = 1;
        length[2] = 1;
        for(long long i = 3;i < N;i++){
            length[i] = length[i - 2] + length[i - 1];
        }
        while(1){
            if(N == 1){
                cout<<"A"<<endl;
                break;
            }
            if(N == 2){
                cout<<"B"<<endl;
                break;
            }
            if(K > length[N - 2]){
                K -= length[N - 2];  
                N -= 1;
            }
            else{
                N -= 2; 
            }
        }
    }
}