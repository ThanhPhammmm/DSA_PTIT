#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string n, string cube){
    int u = 0;
    int v = 0;
    while(u < n.length()){
        if(n[u] == cube[v]){
            u += 1;
            v += 1;
        }
        else{
            u += 1;
        }
    }
    return v == cube.length();
}

int main(){
    int T;
    cin>>T;
    while(T--){
        string n;
        cin>>n;

        int result = 0;
        bool ok = false;

        for(int i = 1;i <= 100;i++){
            int cube = i * i * i;
            if(isSubsequence(n, to_string(cube))){
                result = cube;
                ok = true;
            }
        }

        if(ok){
            cout<<result<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
}