#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int>> C;
vector<int> selected;
vector<bool> used;
vector<vector<int>> results;

void backtrack(int row, int sum){
    if(row == N){
        if(sum == K){
            results.push_back(selected);
        }
        return;
    }
    for(int column = 0;column < N;column++){
        if(!used[column]){
            used[column] = true;
            selected[row] = column + 1; // Chỉ lưu vị trí cột (từ 1 đến N)
            backtrack(row + 1, sum + C[row][column]);
            used[column] = false; // Quay lui
        }
    }
}
int main(){
    cin>>N>>K;
    C.resize(N, vector<int>(N));
    used.resize(N, false);
    selected.resize(N);

    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin>>C[i][j];
        }
    }

    backtrack(0, 0);

    cout << results.size() << endl;

    for(auto res : results){
        for(int x : res){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}