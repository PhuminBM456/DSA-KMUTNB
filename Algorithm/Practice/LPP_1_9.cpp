#include<bits/stdc++.h>

using namespace std;

void A(int n,int sum);

int main(){
    int num;

    cin >> num;

    A(num,0);

    return 0;
}

void A(int n,int sum){
    // basecase
    if(n == 0){
        cout << sum;
        return;
    }

    sum += n%2;

    // recursion
    A(n/2,sum);
}