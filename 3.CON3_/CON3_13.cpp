/*Done*/
/*
Khong hieu + hoc thuoc code
*/
#include <bits/stdc++.h>
using namespace std;

int isArrangable(string s, int d){
    long long n = s.length();
    d = d - 1;//khong hieu
    vector<long long> freq(27, 0);
    for(char c : s){
        freq[c - 'a'] += 1;
    }
    long long maxN = *max_element(freq.begin(),freq.end());

    if(n % d == 0){
        if(maxN > n/d){//khong hieu
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        if(maxN > n/d + 1){//khong hieu
            return 0;
        }
        else{
            return 1;
        }
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int d;
        string s;
        cin>>d>>s;
        int res = isArrangable(s, d);
        if(res){
            cout<<1<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}