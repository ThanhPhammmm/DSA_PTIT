/*Done*/
#include <bits/stdc++.h>
using namespace std;

int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int result = 0;
        for(int i = 9;i >= 0;i--){
            if(N - arr[i] >= 0){
              while(N - arr[i] >= 0){
                N -= arr[i];
                result += 1;
              }  
            }
        }
        cout<<result<<endl;
    }
}