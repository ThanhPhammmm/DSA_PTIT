#include <bits/stdc++.h>
using namespace std;

bool isArrangeable(string S){
    vector<int> alphabet(26, 0);
    for(char c : S){
        alphabet[c - 'a']++;
    }

    for(int i = 0;i < 26;i++){
        if(alphabet[S[i] - 'a'] > (S.length() + 1)/2){
            return 0;
        }
    }
    return 1;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        string S;
        cin>>S;
        if(isArrangeable(S)){
            cout<<"1"<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
}