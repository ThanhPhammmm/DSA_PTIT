#include <bits/stdc++.h>
using namespace std;

int calculate(int num1, int num2, char op){
    if(op == '+'){
        return num1 + num2;
    }
    if(op == '-'){
        return num1 - num2;
    }
    return num1 * num2;
}

bool solve(vector<int> &Arr){
    char ops[] = {'+', '-', '*'};

    /*used to sort its array as the smallest number, 
    so that if we permutate this number(array), it will 
    convert to all possilble situations, and end to the biggest number*/

    /*For ex, arr = {8, 3, 6, 2}
    after sort => arr = {2, 3, 6 ,8}
    final permutation => arr = {8, 6, 3, 2}*/
    
    sort(Arr.begin(), Arr.end());
    do{
        for(char op1 : ops){
            for(char op2 : ops){
                for(char op3 : ops){
                    for(char op4 : ops){
                        int res = calculate(Arr[0], Arr[1], op1);
                        res = calculate(res, Arr[2], op2);
                        res = calculate(res, Arr[3], op3);
                        res = calculate(res, Arr[4], op4);

                        if(res == 23){
                            return 1;
                        }
                    }
                }
            }
        }
    }while(next_permutation(Arr.begin(), Arr.end()));

    return 0;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        vector<int> Arr(5);
        for(int i = 0;i < 5;i++){
            cin>>Arr[i];
        }
        cout<<(solve(Arr) ? "YES" : "NO")<<endl;
    }
}