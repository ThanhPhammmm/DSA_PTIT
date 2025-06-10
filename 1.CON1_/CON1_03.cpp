/*Done*/
#include <bits/stdc++.h>
using namespace std;

void next_permutation(vector<int> &X){
    int N = X.size();
    int index = N - 2;

    //Step 1: Find the index i such that X[i] < X[i + 1]
    while((index >= 0) && (X[index] > X[index + 1])){
        index--;
    }

    //Step 2: Find the largest index j such that X[j] > X[i] (i.e., the smallest number greater than X[i] to the right of i) and swap them.
    if(index >= 0){
        int j = N - 1;
        while(X[j] <= X[index]){
            j--;
        }
        swap(X[index],X[j]);
    }

    //Step 3: Reverse the sequence after index i
    reverse(X.begin() + index + 1, X.end());

}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int> X(N);

        for(int i = 0;i < N;i++){
            cin>>X[i];
        }

        next_permutation(X);

        for(int i = 0;i < N;i++){
            cout<<X[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}