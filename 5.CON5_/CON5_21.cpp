/*Done*/
#include <bits/stdc++.h>
using namespace std;

int countWays = 0;
int N, K;

void  findWays(vector<int> &A, int currentSum){
    if(currentSum == K){
        countWays +=1;
    }
    for(int i = 0;i < N;i++){
        if(currentSum + A[i] <= K){
            findWays(A, currentSum + A[i]);
        }
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>N>>K;
        vector<int> A(N);
        for(int i = 0;i < N;i++){
            cin>>A[i];
        }

        countWays = 0;

        findWays(A, 0);

        cout<<countWays<<endl;
    }
}