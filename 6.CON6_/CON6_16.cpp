/*X*/
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low;j < high;j++){
        if(a[j] < pivot){
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;

}
void quickSort(vector<int> &a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
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

        quickSort(a, 0, n - 1);

        for(int x : a){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}