#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int num7 = n / 7;
        int num4 = 0;
        while(num7 >= 0){
            num4 = (n - 7 * num7);
            if(num4 % 4 == 0){
                num4 /= 4;
                break;
            }
            num7--;
        }
        if(num7 >= 0){
            while(num4--){
                cout<<"4";
            }
            while(num7--){
                cout<<"7";
            }
        }
        else{
            cout<<"-1";
        }
        cout<<endl;
    }
}