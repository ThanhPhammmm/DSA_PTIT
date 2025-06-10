/*Done*/
#include <bits/stdc++.h>
using namespace std;

string result;

void Backtracking(string S, int K){
    if(K == 0){
        return;
    }

    for(int i = 0;i < S.length() - 1;i++){
        for(int j = i + 1;j < S.length();j++){
            if(S[i] < S[j]){
                swap(S[i], S[j]);
                if(S > result){
                    result = S;
                }

                Backtracking(S, K - 1);
                swap(S[i], S[j]);
            }
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int K;
        string S;
        cin>>K>>S;

        result = S;
        Backtracking(S, K);
        
        cout<<result<<endl;
    }
}