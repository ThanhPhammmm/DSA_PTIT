/*X*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    int t; 
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<pair<int, int> > v;
        for(int i = 0; i < n; i ++){
            int x, y; cin >> x >> y;
            v.push_back({x, y});
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> b(n + 1, 1);
        int res = 1;
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < i; j ++)
                if(v[j].second < v[i].first) 
                    b[i] = max(b[i], b[j] + 1);
            res = max(res, b[i]);
        }
        cout << res << endl;
    }
    return 0;
}