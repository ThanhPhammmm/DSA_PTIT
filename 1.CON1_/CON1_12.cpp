#include<bits/stdc++.h>
using namespace std;

void generateBinaryString(int N, int K, string currentString, int ones){
    if(currentString.size() == N){
        if(ones == K){
            cout<<currentString<<endl;
        }
        return;
    }
    //Adding 0
    generateBinaryString(N, K, currentString + "0", ones);

    //Adding 1
    if(ones < K){
        generateBinaryString(N, K, currentString + "1", ones + 1);
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N, K;
        cin>>N>>K;
        generateBinaryString(N, K, "", 0);
    }
    return 0;
}