/*Done*/
#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

long long Pkn(int n, int k) {
    if(k > n){
        return 0;
    }

    long long res = 1;
    
    for(int i = 0;i < k;i++){
        res *= (n - i);
        res = res % mod;
    }

    return res;
}
int main() {
	int t; 
    cin >> t;
	while (t--) {
		int n, k; 
        cin >> n >> k;
		cout << Pkn(n, k) << endl;
	}
}