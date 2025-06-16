/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a;
        for(int i = 0;i < n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }

        vector<int> b = a;
        sort(b.begin(), b.end());

        int left = 0;
        int right = 0;

        for(int i = 0;i < n;i++){
            if(a[i] != b[i]){
                left = i + 1;
                break;
            }
        }
        for(int i = n - 1;i >= 0;i--){
            if(a[i] != b[i]){
                right = i + 1;
                break;
            }
        }

        cout<<left<<" "<<right<<endl;
    }
}