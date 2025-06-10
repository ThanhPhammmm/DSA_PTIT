#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t; 
    cin>>t;
    while(t--)
    {
        int n; 
        cin>>n;
        vector<int> a(n);
        for(int i = 0;i < n;i++){
            cin>>a[i];
        }
        vector<int> b(n);
        b = a;

        sort(b.begin(), b.end());

        int l, r;
        for(int i = 0;i < n;i++){
            if(a[i] != b[i]){
                l = i + 1;
                break;
            }
        }
        for(int j = n - 1;j >= 0;j--){
            if(a[j] != b[j]){
                r = j + 1;
                break;
            }
        }
        cout<<l<<" "<<r<<endl;
    }
}