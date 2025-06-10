/*Done*/
#include <bits/stdc++.h>
using namespace std;

long long VectorToNumber(vector<int> &number){
    int long long result = 0;
    for(int n : number){
        result = 10 * result + n;
    }
    return result;
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

        sort(A.begin(), A.end());

        vector<int> num1;
        vector<int> num2;

        for(int i = 0;i < N;i++){
            if(i % 2 == 0){
                num1.push_back(A[i]);
            }
            else{
                num2.push_back(A[i]);
            }
        }

        long long number1 = VectorToNumber(num1);
        long long number2 = VectorToNumber(num2);

        cout<<number1 + number2<<endl;
    }
}