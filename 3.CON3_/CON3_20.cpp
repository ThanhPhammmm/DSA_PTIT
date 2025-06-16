/*Done*/
/*

balance: biểu thị số lượng [ đã thấy trừ đi số ] đã thấy

Nếu tại một thời điểm nào đó balance < 0 nghĩa là thiếu dấu [, nên cần phải đổi dấu ] đang đứng ở đó với một dấu [ ở bên phải

Mỗi lần như vậy ta sẽ:
Ghi nhớ vị trí của các dấu [ trong một danh sách
Khi thiếu dấu [, ta lấy dấu [ ở gần nhất bên phải để đổi chỗ, và tính tổng số bước cần hoán đổi

*/
#include <bits/stdc++.h>
using namespace std;

int minSwaps(string S){
    vector<int> pos;
    int n = S.length();
    for(int i = 0;i < n;i++){
        if(S[i] == '['){
            pos.push_back(i);
        }
    }

    int balance = 0;
    int swapSteps = 0;
    int p = 0;

    for(int i = 0;i < n;i++){
        if(S[i] == '['){
            balance += 1;
            p += 1;
        }
        else{
            balance -= 1;
            if(balance < 0){
                swapSteps += pos[p] - i; 
                swap(S[i], S[pos[p]]);
                balance = 1;
                p += 1;
            }
        }
    }
    return swapSteps;
}


int main(){
    int T;
    cin>>T;
    while(T--){
        string S;
        cin>>S;
        cout<<minSwaps(S)<<endl;
    }
}