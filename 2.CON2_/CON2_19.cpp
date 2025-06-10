#include <bits/stdc++.h>
using namespace std;

void generateTriangle(vector<int> &A){
    vector<vector<int>> triangle;
    vector<int> current = A;

    while(current.size() > 0){
        triangle.push_back(current);

        vector<int> next;

        for(int i = 0;i < current.size() - 1;i++){
            next.push_back(current[i] + current[i + 1]);
        }
        current = next;
    }

    for(int i = 0;i < triangle.size();i++){
        cout<<"[";
        for(int j = 0;j < triangle[i].size();j++){
            cout<<triangle[i][j];
            if(j < (triangle[i].size() - 1)){
                cout<<" ";
            }
        }
        cout<<"]\n";
    }
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

        generateTriangle(A);
    }
}