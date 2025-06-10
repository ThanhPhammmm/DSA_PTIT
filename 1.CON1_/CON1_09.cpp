/*Done*/
#include <bits/stdc++.h>
using namespace std;

vector<string> generateGray(int n){
    if(n == 1){
        return {"0","1"};
    }
    vector<string> prev = generateGray(n - 1);
    vector<string> result;

    //Add "0" in front of each component of vector prev
    for(string s : prev){
        result.push_back("0" + s);
    }
    //Reverse vector prev
    reverse(prev.begin(), prev.end());

    //Add "1" in front of each component of reversed vector prev
    for(string s : prev){
        result.push_back("1" + s);
    }

    return result;
}
void solve(int n){
    vector<string> grayCodes = generateGray(n);
    for(string code : grayCodes){
        cout<<code<<" ";
    }
    cout<<endl;
}
int main(){
    int T, n;
    cin>>T;
    while(T--){
        cin>>n;
        solve(n);
    }
    return 0;
}