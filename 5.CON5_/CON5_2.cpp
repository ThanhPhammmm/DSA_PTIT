/*Done*/
#include<bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int> &A, int N){
    vector<int> dp(N, 1);

    for(int i = 0;i < N;i++){
        for(int j = 0;j < i;j++){
            if(A[j] < A[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int>A(N);
        for(int i = 0;i < N;i++){
            cin>>A[i];
        }
        int res = longestIncreasingSubsequence(A, N);
        cout<<res<<endl;
    }
}