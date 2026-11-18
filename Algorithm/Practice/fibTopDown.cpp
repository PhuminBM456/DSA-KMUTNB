#include<bits/stdc++.h>
using ll = long long;
using namespace std;

ll fib(int n,map<ll,ll> &memo);

int main(){
    map<ll,ll> memo;

    cout << fib(10,memo);

    return 0;
}

ll fib(int n,map<ll,ll> &memo){
    // basecase
    if(n == 1)
        return 1;

    if(n == 0)
        return 0;

    if(memo.count(n)){
        return memo[n];
    }
    
    // recursion
    memo[n] =  fib(n-1,memo) + fib(n-2,memo);

    return memo[n];
}

/*
ปัญหาใหญ่ -> ปัญหาเล็ก
*/