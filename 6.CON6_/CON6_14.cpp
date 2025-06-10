#include <bits/stdc++.h>
using namespace std;

bool isPrimeNumber(int n){
    if(n < 2){
        return 0;
    }
    for(int i = 2;i <= sqrt(n);i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}


int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;

        bool ok = false;
        for(int i = 2;i <= n;i++){
            if(isPrimeNumber(i) && isPrimeNumber(n - i)){
                ok = true;
                cout<<i<<" "<<n - i;
                break;
            }
        }
        if(!ok){
            cout<<-1<<endl;
        }
        else{
            cout<<endl;
        }
    }
}