/*Done*/
#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> used;
vector<int> seq;
int length = 0;

void backtracking(int index, int n){
    if(n == length){
        for(int i = 0;i < length;i++){
            cout<<s[seq[i]];
        }
        cout<<" ";
        return;
    }
    for(int i = 0;i < length;i++){
        if(!used[i]){
            used[i] = 1;
            seq[index] = i;
            backtracking(index + 1, n + 1);
            used[i] = 0;
            seq[index] = 0;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        length = s.length();
        used.assign(length,0);
        seq.resize(length);
        backtracking(0,0);
        used.clear();
        cout<<endl;
    }
}