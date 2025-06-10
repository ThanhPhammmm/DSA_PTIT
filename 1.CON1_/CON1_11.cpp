/*X*/
#include<bits/stdc++.h>
using namespace std;

vector<string> M, N;

void Sort(int k, int l1, int r1, int l2, int r2) {
	if (k == 0)return;
	sort(M.begin() + l1, M.begin() + r1);
	sort(M.begin() + l2, M.begin() + r2, greater<string>());
	Sort(k - 1, l1, (l1 + r1) / 2, (l1 + r1) / 2, r1);
	Sort(k - 1, l2, (l2 + r2) / 2, (l2 + r2) / 2, r2);
}

int main() {
	int t; 
    cin >> t; 
    while (t--){
		M.clear();
		N.clear();
		string x; 
        cin >> x;
		int n = x.size();
		for(int i = 0;i < pow(2, n);i++){
			auto s = bitset<20>(i).to_string();
			M.push_back(s.substr(20 - n, n));
			N.push_back(s.substr(20 - n, n));
		}
		int sf = pow(2, n);
		Sort(n, 0,  sf / 2, sf / 2, sf);
		for(int i = 0;i < M.size();i++){
			if (N[i] == x) {
				cout << M[i] << endl;
				break;
			}
		}
	}
}