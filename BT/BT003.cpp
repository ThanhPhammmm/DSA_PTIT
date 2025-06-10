#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int maxProductSplit(const vector<int>& A) {
    int total = 0;
    for (int a : A) total += a;

    // bitset để lưu các tổng có thể tạo ra (subset sum)
    bitset<100005> canMake;
    canMake[0] = 1;

    for (int a : A)
        canMake |= (canMake << a);

    int maxProduct = 0;
    for (int s = 0; s <= total; ++s) {
        if (canMake[s]) {
            int product = s * (total - s);
            if (product > maxProduct)
                maxProduct = product;
        }
    }
    return maxProduct;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        cout << maxProductSplit(A) << '\n';
    }
    return 0;
}
