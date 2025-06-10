#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        long long n, k;
        cin>>s>>k;
        n = s.size();

        while(n < k){
            n *= 2;
        }
        while(n > s.size()){
            if(k > (n/2)){
                k = n / 2;
                if(k > 1){
                    k -= 1;
                }
                else{
                    k /= 2;
                }
            }
            n /= 2;
        }
        cout<<s[k - 1]<<endl;
    }
}