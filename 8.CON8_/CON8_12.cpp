/*Done*/
#include <bits/stdc++.h>
using namespace std;

string s, e;

void countSteps(set<string>& a){
    if(s == e){
        cout<<1<<endl;
        return;
    }

    queue<string> q;
    q.push(s);
    int res = 1;

    while(!q.empty()){
        queue<string> tmp = q;
        res += 1;
        while(!tmp.empty()){
            string str = tmp.front();
            tmp.pop();
            q.pop();
            for(int i = 0;i < str.size();i++){
                char ori = str[i];
                for(char j = 'A';j <= 'Z';j++){
                    str[i] = j;
                    if(str == e){
                        cout<<res<<endl;
                        return;
                    }
                    if(a.find(str) != a.end()){
                        q.push(str);
                        a.erase(str);
                    }
                }
                str[i] = ori;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cin>>s>>e;

        set<string> a;
        while(n--){
            string x;
            cin>>x;
            a.insert(x);
        }
        a.erase(s);
        countSteps(a);
    }
}