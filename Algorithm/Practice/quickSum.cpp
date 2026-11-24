#include<bits/stdc++.h>
#define sp ' '
using namespace std;
using vi = vector<int>;

void Recur(vi &v,int i,vi &A);

int main()
{
    int n,start,end;
    vi v;
    vi A;

    cin >> n;
    cin >> start;
    cin >> end;

    v.resize(n);
    A.resize(n);

    Recur(v,0,A);

    /*
    10 2 6
    1 2 3 4 5 6 7 8 9 10

    2 + 3 + 4 + 5 + 6 = 20
    */

    if(start == end) {
        cout << A[start-1];
    } else if(start == 1) {
        cout << A[end-1];
    } else{
        cout << A[end-1] - A[start-2] << endl;
    }

    return 0;
}

void Recur(vi &v,int i,vi &A)
{
    // basecase
    if(i == v.size())
        return;

    int temp;

    cin >> temp;

    v[i] = temp;
    
    if(i == 0) {
        A[0] = v[0];
    }else {
        A[i] = v[i] + A[i-1];
    }

    // recursion
    Recur(v,i+1,A);
}
