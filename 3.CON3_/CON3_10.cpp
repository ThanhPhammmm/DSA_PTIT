/*Done*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for(int i = 0;i < N;i++){
            long long x;
            cin>>x;
            pq.push(x);
        }

        long long total_cost = 0;
        while(pq.size() > 1){
            long long num1 = pq.top();
            pq.pop();
            long long num2 = pq.top();
            pq.pop();

            long long cost = num1 + num2;
            total_cost += cost;
            pq.push(cost);
        }
        cout<<total_cost<<endl;
    }
}