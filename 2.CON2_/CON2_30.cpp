#include <bits/stdc++.h>
using namespace std;

long long N, P, S;
vector<long long> A;
int countSub = 0;
vector<vector<long long>>B;

bool isPrime(long long j){
    if (j < 2) return false;          // 0, 1, âm => không phải số nguyên tố
    if (j == 2) return true;          // 2 là số nguyên tố
    if (j % 2 == 0) return false;     // Số chẵn khác 2 không phải số nguyên tố

    for (int i = 3; i <= int(sqrt(j)); i += 2) {
        if (j % i == 0) return false;
    }
    return true;
}

void backtracking(long long start, int size_of_buff, long long currentSum){
    if(size_of_buff > N){
        return;
    }
    if(size_of_buff == N && currentSum == S){
        countSub += 1;
        B.push_back(A);
        return;
    }
    for(long long j = start;j <= S;j++){
        if(isPrime(j)){
            if(j + currentSum <= S){
                A.push_back(j);
                backtracking(j + 1, size_of_buff + 1, currentSum + j);
                A.pop_back();
            }
            else{
                break;
            }
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>N>>P>>S;
        countSub = 0;
        backtracking(P + 1,0,0);

        cout<<countSub<<endl;

        for(auto x : B){
            for(long long i : x){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        A.clear();
        B.clear();
    }
}