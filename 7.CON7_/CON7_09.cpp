#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> indexofPairs(string &expr){
    stack<int> pairs;
    vector<pair<int, int>> result;

    for(int i = 0;i < expr.length();i++){
        if(expr[i] == '('){
            pairs.push(i);
        }
        else if(expr[i] == ')'){
            char temp = pairs.top();
            result.push_back(make_pair(temp, i));
            pairs.pop();
        }
    }
    return result;
}
int main(){
    string expr;
    cin>>expr;

    vector<pair<int, int>> index = indexofPairs(expr);

    int n = index.size();

    set<string> result;

    for(int mask = 1;mask < (1 << n);mask++){
        vector<bool> check(expr.length(), false);
        for(int i = 0;i < n;i++){
            if((mask & (1 << i))){
                check[index[i].first] = true;
                check[index[i].second] = true;
            }
        }

        string s = "";

        for(int i = 0;i < expr.length();i++){
            if(!check[i]){
                s.push_back(expr[i]);
            }
        }

        result.insert(s);
    }

    for(string rs : result){
        cout<<rs<<endl;
    }
}
