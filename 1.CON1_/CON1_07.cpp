#include<bits/stdc++.h>
using namespace std;

void backtrack(int n, int sum, vector<int> &current, int last){
    if(sum == n){
        cout<<'(';
        for(size_t i = 0;i < current.size();i++){
            cout<<current[i];
            if(i != (current.size() - 1)){
                cout<<" ";
            }
        }
        cout<<") ";
        return;
    }

    for(int i = last;i >= 1;i--){
        if(sum + i <= n){
            current.push_back(i);
            backtrack(n, sum + i, current, i);
            current.pop_back();
        }
    }
}
void generatePatritions(int N){
    vector<int> current;
    backtrack(N, 0, current, N);
    cout<<endl;
}
int main(){
    int T, N;
    cin>>T;
    while(T--){
        cin>>N;
        generatePatritions(N);
    }
    return 0;
}