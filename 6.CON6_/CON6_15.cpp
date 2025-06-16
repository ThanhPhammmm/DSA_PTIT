/*X*/
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0;i < n1;i++){
        L[i] = a[left + i];
    }
    for(int j = 0;j < n2;j++){
        R[j] = a[mid + 1 + j];
    }

    int i_left = 0;
    int i_right = 0;
    int k = left;

    while(i_left < n1 && i_right < n2){
        if(L[i_left] > R[i_right]){
            a[k] = R[i_right];
            i_right++;
        }
        else{
            a[k] = L[i_left];
            i_left++;
        }
        k++;
    }

    while(i_left < n1){
        a[k] = L[i_left];
        i_left++;
        k++;
    }
    while(i_right < n2){
        a[k] = R[i_right];
        i_right++;
        k++;
    }
}
void mergeSort(vector<int> &a, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid ,right);
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0;i < n;i++){
            cin>>a[i];
        }
        mergeSort(a, 0, n - 1);

        for(int x : a){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}