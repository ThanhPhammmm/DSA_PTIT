/*Done*/
/*Ouput mẫu sai, không có cách giữa các tổ hợp*/
/*Ví dụ: [2 2 2 2][2 2 4][2 6][4 4][8]*/

#include <bits/stdc++.h>
using namespace std;

int N, X;
int A[105];
vector<int> result;
bool ok = false;

void backtracking(int index, int currentSum){
    if(currentSum == X){
        cout<<'[';
        for(size_t i = 0;i < result.size();i++){
            cout<<result[i];
            if(i < result.size() - 1){
                cout<<" ";
            }
        }
        cout<<"]";
        ok = true;
    }

    for(int j = index;j < N;j++){
        if(currentSum + A[j] <= X){
            result.push_back(A[j]);
            backtracking(j, currentSum + A[j]);
            result.pop_back();
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>N>>X;
        for(int i = 0;i < N;i++){
            cin>>A[i];
        }
        
        sort(A, A + N);  // Sửa 1: sắp xếp để có thứ tự tăng
        result.clear();
        ok = false;

        backtracking(0, 0);

        if(!ok){
            cout<<"-1\n";
        }
        else{
            cout<<"\n";
        }
    }
}