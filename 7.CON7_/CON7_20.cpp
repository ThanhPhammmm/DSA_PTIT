/*Done*/
#include <bits/stdc++.h>
using namespace std;

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
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = 0;i < n;i++){
            while(st.size() > 0 && a[i] > a[st.top()]){
                ans[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
        for(int num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}