#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterIndex(vector<int> &a){
    vector<int>nGi(a.size(), -1);
    stack<int> index;

    for(int i = 0;i < a.size();i++){
        while((index.size() > 0) && a[i] > a[index.top()]){
            nGi[index.top()] = i;
            index.pop();
        }
        index.push(i);
    }
    return nGi;
}
int nextSmallerIndex(vector<int> &a, int start){
    for(int i = start + 1;i < a.size();i++){
        if(a[i] < a[start]){
            return a[i];
        }
    }
    return -1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int &num : a){
            cin>>num;
        }

        vector<int> b = nextGreaterIndex(a);
        vector<int> ans(n, -1);
        for(int i = 0;i < n;i++){
            if(b[i] != -1){
                ans[i] = nextSmallerIndex(a, b[i]);
            }
        }
        for(int num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}