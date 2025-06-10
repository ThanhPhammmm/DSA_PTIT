#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<long long> &A, long long N, long long K){
    int left = 0, right = N - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(A[mid] == K){
            return mid + 1;
        }
        else if(A[mid] > K){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        long long N, K;
        cin>>N>>K;
        vector<long long> A(N);
        for(int i = 0;i < N;i++){
            cin>>A[i];
        }

        int result = binarySearch(A, N, K);
        if(result == -1){
            cout<<"NO\n";
        }
        else{
            cout<<result<<"\n";
        }
    }
}