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
        for(int i = 0;i < n;i++){
            cin>>a[i];
        }

        int res = 0;

        for(int i = 0;i < n;i++){
            int pivot = i;
            for(int j = i + 1;j < n;j++){
                if(a[pivot] > a[j]){
                    pivot = j;
                }
            }
            if(i != pivot){
                res += 1;
                swap(a[i],a[pivot]);
            }
        }
        cout<<res<<endl;
    }
}
