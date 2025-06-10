#include <bits/stdc++.h>
using namespace std;

bool next_combination(vector<int> &comb, int N, int K){
    int i = K - 1;
    while(i >=0 && comb[i] == (N - K + i + 1)){
        i--;
    }

    // Đã là tổ hợp cuối cùng
    if(i < 0){
        return false;
    }

    comb[i]++;
    for(int j = i + 1;j < K;j++){
        comb[j] = comb[j - 1] + 1;
    }
    return true;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N, K;
        cin>>N>>K;

        vector<int> currentTeam(K);
        for(int i = 0;i < K;i++){
            cin>>currentTeam[i];
        }

        // Tạo bản sao để sinh tổ hợp tiếp theo
        vector<int> nextTeam = currentTeam;

        // Nếu không có tổ hợp tiếp theo, toàn bộ K chiến sĩ nghỉ
        if(!next_combination(nextTeam, N, K)){
            cout<<K<<endl;
        }
        else{
            // Đếm số chiến sĩ bị thay đổi giữa hai nhóm
            int count = 0;
            unordered_set<int> old_team(currentTeam.begin(), currentTeam.end());
            for(int i = 0;i < K;i++){
                if(!old_team.count(nextTeam[i])){
                    count++;
                }
            }
            cout<<count<<endl;

        }
    }
}
