#include <bits/stdc++.h>
using namespace std;

void generateReverseTriangle(vector<int> &A){
    vector<vector<int>> reverseTriangle;
    vector<int> current = A;

    while(!current.empty()){
        reverseTriangle.push_back(current);

        vector<int> next;

        for(int i = 0;i < current.size() - 1;i++){
            next.push_back(current[i] + current[i + 1]);    
        }

        current = next;
    }

    for(int i = reverseTriangle.size() - 1;i >= 0;i--){
        cout<<"[";
        for(int j = 0;j < reverseTriangle[i].size();j++){
            cout<<reverseTriangle[i][j];
            if(j < (reverseTriangle[i].size() - 1)){
                cout<<" ";
            }
        }
        cout<<"] ";
    }
    cout<<"\n";
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i = 0;i < N;i++){
            cin>>A[i];
        }
        generateReverseTriangle(A);
    }
}
