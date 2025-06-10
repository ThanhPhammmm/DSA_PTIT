#include <bits/stdc++.h>
using namespace std;

int maxBitonicSum(const vector<int>& A, int N) {
    vector<int> inc(N), dec(N);

    for(int i = 0;i < N;i++){
        inc[i] = A[i];
        for(int j = 0;j < i;j++){
            if(A[j] < A[i] && inc[i] < A[i] + inc[j] ){
                inc[i] = inc[j] + A[i];
            }
        }
    }

    for(int i = N - 1;i >= 0;i--){
        dec[i] = A[i];
        for(int j = N - 1;j > i;j--){
            if(A[i] > A[j] && dec[i] < A[i] + dec[j] ){
                dec[i] = A[i] + dec[j];
            }
        }
    }

    int maxSum = 0;
    for(int i = 0;i < N;i++){
        maxSum = max(maxSum, inc[i] + dec[i] - A[i]); 
    }

    return maxSum;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        cout << maxBitonicSum(A, N) << endl;
    }

    return 0;
}
