#include <bits/stdc++.h>
using namespace std;

int N, K;
bool found = false;
vector<int> subset;
vector<int> A;

void Try(int i, int sum){
    if(sum > K){
        return;
    }
    if(sum == K){
        found = true;
        cout<<"[";
        for(int j = 0;j < subset.size();j++){
            cout<<subset[j];
            if(j < subset.size() - 1){
                cout<<" ";
            }
        }
        cout<<"] ";
        return;
    }
    for(int j = i;j < N;j++){
        subset.push_back(A[j]);
        Try(j + 1, sum + A[j]);
        subset.pop_back();
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>N>>K;
        A.resize(N);
        for(int i = 0;i < N;i++){
            cin>>A[i];
        }
        sort(A.begin(), A.end());
        found = false;
        subset.clear();
        Try(0, 0);

        if(!found){
            cout<<"-1";
        }
        cout<<endl;
    }
}

