/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        string a, b;
        cin>>k>>a>>b;
        
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        if(i < j){
            swap(i ,j);
            swap(a, b);
        }

        string answer = "";
        while(i >= 0 && j >= 0){
            int sum = (a[i] - '0') + (b[j] - '0') + carry;
            answer = to_string(sum % k) + answer;
            carry = sum / k; 
            i--;
            j--;
        }

        while(i >= 0){
            int sum = (a[i] - '0') + carry;
            answer = to_string(sum % k) + answer;
            carry = sum / k;
            i--;
        }

        if(carry > 0){
            answer = to_string(carry) + answer;
        }
        
        cout<<answer<<endl;
    }
}