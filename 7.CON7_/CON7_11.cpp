/*Done*/
#include <bits/stdc++.h>
using namespace std;

int precedence(char op){
	if(op == '+' || op == '-'){
		return 1;
	}
	if(op == '*' || op =='/'){
		return 2;
	}
	return 0;
}
string InfixtoPostfix(string s){
	string result = "";
	stack<char> temp;
	for(int i = 0;i < s.length();i++){
		if(isalpha(s[i])){
			result += s[i];
		}
		else if(s[i] == '('){
			temp.push(s[i]);
		}
		else if(s[i] == ')'){
			while(temp.size() > 0 && temp.top() != '('){
				result += temp.top();
				temp.pop();
			}
			if(temp.size() > 0) temp.pop();		//xoa dau '('
		}
		else{
			while(temp.size() > 0 && precedence(temp.top()) >= precedence(s[i])){
				result += temp.top();
				temp.pop();
			}
			temp.push(s[i]);
		}
	}
	while(temp.size()){
		result += temp.top();
		temp.pop();
	}
	return result;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<InfixtoPostfix(s)<<endl;
	}
}
