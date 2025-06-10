/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
    cin >> t;
	stack<int>nx;
	while (t--) {
        string s;
		cin >> s;
        
		if (s == "PUSH") {
            int n;
			cin >> n;
			nx.push(n);
		}
		else if (s == "POP" && !nx.empty())nx.pop();
		else if (s == "PRINT") {
			if (!nx.empty())cout << nx.top() << endl;
			else cout << "NONE" << endl;
		}
	}
}