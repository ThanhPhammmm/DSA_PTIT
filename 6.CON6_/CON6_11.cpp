/*Done*/

/*
Lưu ý, test chọn cặp số gần nhất bằng 0 sớm nhất
*/
/*
Ví dụ: 3, -2, 5, -4
=>Nó sẽ trả về 1(3,-2)
=>Không nên sort

Nếu sort => -4 -2 3 5 => trả về -1(-4,3)
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int M[1000];
		for (int i = 0; i < n; i++)cin >> M[i];
		int res = INT_MAX;
		int minnn = INT_MAX;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if (abs(M[i] + M[j]) < minnn) {
					minnn = abs(M[i] + M[j]);
					res = M[i] + M[j];
				}
				
		cout << res << endl;
	}
}