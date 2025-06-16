/*Done*/
#include<bits/stdc++.h>
using namespace std;

/*
--Vô hướng--
Chu trình Euler: mọi đỉnh bậc chẵn
Đường đi Euler: đúng 2 hoặc 0 đỉnh bậc lẻ
*/


int main(){
    int t;
    cin>>t;
    while(t--){
        int v, e;
        cin>>v>>e;
        vector<int> deg(v + 1, 0);
        while(e--){
            int x, y;
            cin>>x>>y;
            deg[x]++;
            deg[y]++;
        }
        int oddCount = 0;
        for(int num : deg){
            if(num % 2 != 0){
                oddCount += 1;
            }
        }

        if(oddCount == 0){
            cout<<2<<endl;
        }
        else if(oddCount == 2){
            cout<<1<<endl;
        }
        else{
            cout<<0;
        }
    }
}
