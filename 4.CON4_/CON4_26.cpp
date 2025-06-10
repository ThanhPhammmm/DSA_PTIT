#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int T;
    cin>>T;
    while(T--){
        ll K;
        string A, B;
        cin>>K>>A>>B;
        int carry = 0;

        string answer = "";

        int i = A.size() - 1;
        int j = B.size() - 1;

        if(i < j){
            swap(i, j);
            swap(A, B);
        }

        while(i >= 0 && j >= 0){
            int sum = (A[i] - '0') + (B[j] - '0') + carry;
            carry = sum / K;
            answer = to_string(sum % K) + answer;
            i--;
            j--;
        }
        while(i >= 0){
            int sum = (A[i] - '0') + carry;
            carry = sum / K;
            answer = to_string(sum % K) + answer;
            i--;
        }

        if(carry){
            answer = to_string(carry) + answer;
        }

        cout<<answer<<endl;
    }
}
