#include <bits/stdc++.h>
using namespace std;

int binary_search_rotated(vector<int> &A, int x){
    int left = 0;
    int right = A.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(A[mid] == x){
            return mid;
        }

        if(A[left] <= A[mid]){
            if(A[left] <= x && x < A[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(A[mid] <= x && x < A[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n, x;
        cin>>n>>x;
        vector<int> A(n);
        for(int i = 0;i < n;i++){
            cin>>A[i];
        }
        int position = binary_search_rotated(A, x); 
        cout<<position + 1<<endl;
    }
}