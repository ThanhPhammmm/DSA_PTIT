/*Done*/
#include<bits/stdc++.h>
using namespace std;

int caculate(int a, int b, char op){
	if(op == '+') return a + b;
	if(op == '-') return a - b;
	if(op == '*') return a * b;
	if(op == '/') return a / b;

	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<int> calc;
		
		for(int i = 0;i < s.length();i++){
			if(s[i] >= '0' && s[i] <= '9'){
				calc.push(s[i] - '0');
			}
			else{
				int a = calc.top();
				calc.pop();
				int b = calc.top();
				calc.pop();
				int c = caculate(b, a, s[i]);
				calc.push(c);
			}
		}

		cout<<calc.top()<<endl;
	}
}