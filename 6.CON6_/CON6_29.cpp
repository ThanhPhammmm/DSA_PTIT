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

        int count = 1;

        for(int i = 0;i < n;i++){
            bool isSwap = false;
            for(int j = 0;j < n - i - 1;j++){
                if(a[j] > a[j + 1]){
                    swap(a[j], a[j + 1]);
                    isSwap = true;
                }
            }
            if(isSwap){
                cout<<"Buoc "<<count<<": ";
                for(int n : a){
                    cout<<n<<" ";
                }
                count += 1;
                cout<<endl;
            }
        }
    }
}