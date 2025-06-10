#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; 
    cin >> t; 
	while(t--){
		string str; 
        cin>>str;
		stack <char> stk;
		bool ok = true;
		for(int i = 0; i < str.size(); i ++){
			if(str[i] == '{' || str[i] == '[' || str[i]=='(') 
				stk.push(str[i]);
			else if(str[i]=='}'){
				if(stk.empty()) ok = false;
				else if(stk.top()=='{') stk.pop();
			}
			else if(str[i]==']'){
				if(stk.empty()) ok = false;
				else if(stk.top()=='[') stk.pop();
			}
			else if(str[i]==')'){
				if(stk.empty()) ok = false;
				else if(stk.top()=='(') stk.pop();
			}
		}
		if(stk.size() > 0) 
			ok = false;
		if(ok) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}