#include<bits/stdc++.h>

using namespace std;

void fib(int n){
    int arr[n] = {0};
    int sum = 0;

    arr[0] = 0;
    arr[1] = 1;

    for(int i=0;i<=n;++i){
        if(i == 0 || i == 1)
            continue;

        arr[i] = arr[i-2] + arr[i-1];
    }

    cout << arr[n];
}

int main(){
    fib(10);

    return 0;
}

/*
ปัญหาเล็ก -> ปัญหาใหญ่
*/