#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> h(n);
        for(int &num : h){
            cin>>num;
        }
        int result = INT_MIN;
        for(int i = 0;i < n;i++){
            int left = i - 1;
            int right = i + 1;
            int quan = 1;
            while(left >= 0){
                if(h[i] <= h[left]){
                    quan += 1;
                    left--;
                }
                else{
                    break;
                }
            }
            while(right <= n - 1){
                if(h[i] <= h[right]){
                    quan += 1;
                    right++;
                }
                else{
                    break;
                }
            }
            result = max(result, quan * h[i]);
        }
        cout<<result<<endl;
    }
}