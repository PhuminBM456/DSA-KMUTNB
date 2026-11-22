#include<bits/stdc++.h>
#define sp ' '
using namespace std;
using vi = vector<int>;

void Iteration(vi &v,int n);
void A(vi &v,int i,int n);
void B(vi &v,int j);

int main()
{
    vi v;
    int n;

    cin >> n;

    v.resize(n);

    for(int i=0;i<n;++i)
    {
        cin >> v[i];
    }

    //A(v,0,n);
    Iteration(v,n);

    for(int a : v)
    {
        cout << a << sp;
    }

    return 0;
}

void Iteration(vi &v,int n)
{
    for(int i=0;i<n;i++){
        int j=i;
        
        while(true)
        {
            if(j == 0)
            {
                break;
            }

            if(v[j] < v[j-1])
            {
                swap(v[j],v[j-1]);
            }else
            {
                break;
            }

            --j;
        }
    }
}

void A(vi &v,int i,int n)
{
    // basecase
    if(i == n)
    {
        return;
    }

    int j = i;
    B(v,j);

    A(v,i+1,n);
}

void B(vi &v,int j)
{
    // basecase
    if(j == 0)
    {
        return;
    }

    if(v[j] < v[j-1])
    {
        swap(v[j],v[j-1]);
    }else
    {
        return;
    }

    // recursion
    B(v,j-1);
}