#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		int arr[N + 1];
		for(int i = 0;i < N;i++){
			cin>>arr[i];
		}

		int result = INT_MIN;

		for(int i = 0;i < N;i++){
			int temp_sum = arr[i];
			for(int j = i + 1;j < N;j++){
				temp_sum += arr[j];
				if(temp_sum > result){
					result = temp_sum;
				}
			}
		}
		cout<<result<<endl;
	}
}