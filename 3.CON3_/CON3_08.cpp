#include <bits/stdc++.h>
using namespace std;

class Job{
    public:
        int start;
        int end;
};
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<Job> A(N);

        for(int i = 0;i < N;i++){
            cin>>A[i].start;
        }
        for(int j = 0;j < N;j++){
            cin>>A[j].end;
        }

        sort(A.begin(), A.end(), [](Job a, Job b){ return a.end < b.end;});

        int cnt = 0;
        int currentEnd = -1;

        for(int k = 0;k < N;k++){
            if(A[k].start >= currentEnd){
                cnt += 1;
                currentEnd = A[k].end;
            }
        }

        cout<<cnt<<endl;
    }
}