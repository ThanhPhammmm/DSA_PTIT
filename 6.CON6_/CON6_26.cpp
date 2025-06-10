#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> A(n);
        for(int i = 0;i < n;i++){
            cin>>A[i];
        }
        for(int i = 0;i < n - 1;i++){
            for(int j = i + 1;j < n;j++){
                if(A[j] < A[i]){
                    swap(A[i], A[j]);
                }
            }
            cout<<"Buoc "<<i + 1<<": ";
            for(int c : A){
                cout<<c<<" ";
            }
            cout<<endl;
        }
    }
}