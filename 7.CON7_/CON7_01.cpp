#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    string command;
    while(cin>>command){
        if(command == "push"){
            int x;
            cin>>x;
            st.push(x);
        }
        else if(command == "pop"){
            if(!st.empty()){
                st.pop();
            }
        }
        else if(command == "show"){
            if(st.empty()){
                cout<<"empty";
            }
            else{
                vector<int> result;
                stack<int> temp_st = st;
                while(!temp_st.empty()){
                    int x = temp_st.top();
                    temp_st.pop();
                    result.push_back(x);
                }

                for(int i = result.size() - 1;i >= 0;i--){
                    cout<<result[i]<<" ";
                }
            }
            cout<<endl;
        }
    }
}