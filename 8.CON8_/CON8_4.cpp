/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        string s;
        cin>>s;
        
        map<char,int> a;
        for(int i = 0;i < s.length();i++){
            a[s[i]]++;
        }

        priority_queue<int> q;
        for(pair<char,int> c : a){
            q.push(c.second);
        }

        while(k--){
            int temp = q.top();
            q.pop();
            temp--;
            q.push(temp);
        }

        int res = 0;
        while(!q.empty()){
            int temp = q.top();
            q.pop();
            res += temp * temp;
        }
        
        cout<<res<<endl;
    }
}