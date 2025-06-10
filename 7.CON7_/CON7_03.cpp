#include <bits/stdc++.h>
using namespace std;

string daotu(string s) {
    stringstream ss(s);
    string word, res;
    while (ss >> word) {
        reverse(word.begin(), word.end()); // Đ?o ngư?c t?
        res += word + " "; // Thêm t? vào k?t qu?
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); 
    while(t--){
    	string s;
		getline(cin,s);
		cout << daotu(s) << endl; 
	} 
}