#include <bits/stdc++.h>
using namespace std;

long long binaryToDecimal(string S){
    int num = 0;
    int index = 0;
    for(int i = S.length() - 1;i >= 0;i--){
        num = num + (1 << index++) * (S[i] - '0'); 
    }
    return num;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        string S1, S2;
        cin>>S1>>S2;

        long long num1 = binaryToDecimal(S1);
        long long num2 = binaryToDecimal(S2);
        long long result = num1 * num2;
        cout<<result<<endl;
    }
}