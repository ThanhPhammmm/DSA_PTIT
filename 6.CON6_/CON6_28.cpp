#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0;i < n;i++){
            cin>>a[i];
        }

        vector<vector<int>> steps;

        for(int i = 0;i < n;i++){
            int key = a[i];
            int j = i - 1;
            while(j >= 0 && key < a[j]){
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;

            vector<int> tmp(a.begin(), a.begin() + i + 1);
            steps.push_back(tmp);
        }

        for(int i = steps.size() - 1;i >= 0;i--){
            cout<<"Buoc "<<i<<": ";
            for(int n : steps[i]){
                cout<<n<<" ";
            }
            cout<<endl;
        }
    }
}