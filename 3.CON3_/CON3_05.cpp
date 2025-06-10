#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N, K;
        cin>>N>>K;
        vector<int> A(N);
        int sum = 0;
        for(int i = 0;i < N;i++){
            cin>>A[i];
            sum += A[i];
        }
        sort(A.begin(), A.end());
        int sum_of_small_K = accumulate(A.begin(), A.begin() + K, 0);
        int sum_of_big_K = accumulate(A.end() - K, A.end(), 0);

        int result = max(abs(sum - 2 * sum_of_small_K), abs(sum - 2 * sum_of_big_K));

        cout<<result<<endl;
    }
}