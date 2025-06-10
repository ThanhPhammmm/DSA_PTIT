#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t = 1, n, mod = 1e9 + 7, sum, tmp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        while(n--)
        {
            cin >> tmp;
            pq.push(tmp);
        }
        sum = 0;
        while(pq.size() > 1)
        {
            tmp = pq.top();
            pq.pop();
            tmp += pq.top();
            pq.pop();
            if(tmp >= mod) tmp -= mod;
            sum += tmp;
            if(sum >= mod) sum -= mod;
            pq.push(tmp);
        }
        cout << sum << endl;
    }
    return 0;
}