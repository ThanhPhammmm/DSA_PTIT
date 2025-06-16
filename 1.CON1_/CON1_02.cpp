/*Done*/
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &a, int n, int k){
    int i = a.size() - 1;
    while(i >= 0 && a[i] == n - k + i + 1){
        i--;
    }
    if(i != -1){
        a[i] += 1;
        for(int j = i + 1;j < a.size();j++){
            a[j] = a[j - 1] + 1;
        }
    }
    else{
        for(int j = 0;j < a.size();j++){
            a[j] = j + 1;
        }
    }
    for(int num : a){
        cout<<num<<" ";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> a(k);
        for(int i = 0;i < k;i++){
            cin>>a[i];
        }
        solve(a, n, k);
        cout<<endl;
    }
}