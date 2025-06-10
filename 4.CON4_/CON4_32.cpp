#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll mergerAndCount(vector<ll> &A, long long mid, long long left, long long right){
    long long i = left;
    long long j = mid + 1;
    
    long long count = 0;

    vector<ll> temp;

    while(i <= mid && j <= right){
        if(A[i] <=  A[j]){
            temp.push_back(A[i]);
            i++;
        }
        else{
            temp.push_back(A[j]);
            j++;
            count += mid  - i + 1;
        }
    }
    while(i <= mid){
        temp.push_back(A[i++]);
    }
    while(j <= right){
        temp.push_back(A[j++]);
    }

    for(int i = left;i <= right;i++){
        A[i] = temp[i - left];
    }

    return count;
}
ll mergeSortAndCount(vector<ll> &A, long long left, long long right){
    if(left == right){
        return 0;
    }
    long long mid = (left + right) / 2;
    ll count = 0;
    count += mergeSortAndCount(A, left, mid);
    count += mergeSortAndCount(A, mid + 1, right);
    count += mergerAndCount(A, mid, left, right);
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<ll> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        cout << mergeSortAndCount(A, 0, N - 1) << endl;
    }
    return 0;
}
