#include<bits/stdc++.h>
#define sp ' '
using namespace std;
using vi = vector<int>;

void A(vi &v,int start,int end,int checker);
int B(vi &v,int start,int end,int sum);

int main()
{
    vi v;
    int n;

    cin >> n;

    v.resize(n);

    for(int i=0;i<n;++i){
        cin >> v[i];
    }

    return 0;
}

void A(vi &v,int start,int end,int checker)
{
    // basecase
    
    
    // recursion
    int mid = start + (end-start) / 2;

    if((end - start + 1) % 2 == 0) { // even
        int left,right,ansLeft,ansRight;
        
        ansLeft = (mid - start+1) * checker;
        ansRight = (end - mid+1) * checker;
        left = B(v,start,mid);
        right = B(v,mid+1,end);

        if(left != ansLeft) {
            A(v,start,mid,checker);
        }

        if(right != ansRight) {
            A(v,mid+1,end,checker);
        }
    }else {
        int left,right,ansLeft,ansRight;

        
    }
}

int B(vi &v,int start,int end,int sum)
{
    // basecase
    if(start == end) {
        sum += v[end];
        return sum;
    }

    // recursion
    return B(v,start+1,end,sum);
}