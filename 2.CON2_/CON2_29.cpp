#include <bits/stdc++.h>
using namespace std;

int M, N;
int result = 0;
int A[105][105];

void backtracking(int row, int column){
    if((row == M - 1) && (column == N - 1)){
        result += 1;
        return;
    }

    if(row < M - 1){
        backtracking(row + 1, column);
    }
    if(column < N - 1){
        backtracking(row, column + 1);
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>M>>N;
        for(int i = 0;i < M;i++){
            for(int j = 0;j < N;j++){
                cin>>A[i][j];
            }
        }
        result = 0;
        backtracking(0, 0);

        cout<<result<<endl;
    }
}
