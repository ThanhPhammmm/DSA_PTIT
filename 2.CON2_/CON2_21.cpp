#include <bits/stdc++.h>
using namespace std;

bool check[105] = {false};
int length_of_string;
int x[105];
string s;

void backtracking(int index){
    for(int i = 0;i < length_of_string;i++){
        if(!check[i]){
            check[i] = true;
            x[index] = i;
            if(index == (length_of_string - 1)){
                for(int j = 0;j < length_of_string;j++){
                    cout<<s[x[j]];
                }
                cout<<" ";
            }
            else{
                backtracking(index + 1);
            }
            check[i] = false;
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>s;
        length_of_string = s.length();
        backtracking(0);
        memset(check, false, sizeof(check));
        memset(x, 0, sizeof(x));
        cout<<"\n";
    }
}