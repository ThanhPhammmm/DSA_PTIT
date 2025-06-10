#include <bits/stdc++.h>
using namespace std;

void solve(int S, int D){
    if(S > 9 * D){
        cout<<-1; 
        return;
    }   

    vector<int> digits(D);

    for(int i = D - 1;i >= 0;i--){
        if(S > 9){
            digits[i] = 9;
            S -= 9;
        }
        else{
            digits[i] = S;
            S = 0;
        }
    }

    if(digits[0] == 0){
        for(int i = 1;i < digits.size();i++){
            if(digits[i] > 0){
                digits[i]--;
                digits[0] = 1;
                break;
            }
        }
    }

    for(int n : digits){
        cout<<n;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int S, D;
        cin>>S>>D;

        solve(S, D);
        cout<<endl;
    }
}