#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
long long sum= 0;
int arr[1000];
long long S;
bool valid = false;
int n;

void Try(int current_index){
    if(valid){
        return;
    }
    for(int i = 1;i >= 0;i--){
        sum += arr[current_index] * i;
        cnt += i;
        if(sum == S){
            cout<<cnt<<endl;
            valid = true;
            return;
        }
        if(sum < S && current_index < n){
            Try(current_index + 1);
        }
        sum -= arr[current_index] * i;
        cnt -= i;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        valid = false;
        n = 0;
        S = 0;
        cin>>n>>S;
        for(int i = 0;i < n;i++){
            cin>>arr[i];
        }
        sort(arr, arr + n, greater<>());
        Try(0);
        if(!valid){
            cout<<-1<<endl;
        }
    }
}