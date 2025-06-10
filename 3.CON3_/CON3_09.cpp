/*Done*/
#include <bits/stdc++.h>
using namespace std;

class Job{
    public:
    int id;
    int deadline;
    int profit;
};

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<Job> A(N);
        for(int i = 0;i < N;i++){
            cin>>A[i].id>>A[i].deadline>>A[i].profit;
        }

        sort(A.begin(), A.end(), [](Job a, Job b){return a.profit > b.profit;});

        int maxDeadline = 0;
        for(auto job : A){
            maxDeadline = max(maxDeadline, job.deadline);
        }

        vector<bool> slot(maxDeadline + 1, false);

        int count = 0;
        int profit = 0;

        for(auto job : A){
            for(int t = job.deadline;t >= 1;t--){
                if(!slot[t]){
                    count += 1;
                    profit += job.profit;
                    slot[t] = true;
                    break;
                }
            }
        }

        cout<<count<<" "<<profit<<endl;
    }
}