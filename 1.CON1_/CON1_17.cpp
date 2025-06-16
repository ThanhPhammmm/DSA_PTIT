/*Done*/
#include <bits/stdc++.h>
using namespace std;

string findSmallestMultiple(int N){
    queue<pair<string, int>> q;
    set<int> used;

    q.push({"9", 9 % N});
    while(!q.empty()){
        auto [num, reminder] = q.front();
        q.pop();

        if(reminder == 0){
            return num;
        }

        if(used.find(reminder) == used.end()){
            used.insert(reminder);

            q.push({num + "0", (reminder * 10) % N});       //Ghi nho
            q.push({num + "9", (reminder * 10 + 9) % N});   //Ghi nho
        }
    }
    return "-1";
}
int main() {
    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;
        cout << findSmallestMultiple(N) << endl;
    }

    return 0;
}
