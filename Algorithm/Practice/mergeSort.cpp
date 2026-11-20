#include<bits/stdc++.h>
#define sp ' '
using namespace std;
using vi = vector<int>;

void mergesort(vi &v,int start,int end);
void merge(vi &v,int start,int mid,int end);

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

    mergesort(v,0,n-1);

    for(int a : v)
    {
        cout << a << sp;
    }

    return 0;
}

void mergesort(vi &v,int start,int end)
{
    // basecase
    if(start == end)
        return;

    int mid = start + (end-start) / 2;
    mergesort(v,start,mid);
    mergesort(v,mid+1,end);
    merge(v,start,mid,end);
}

void merge(vi &v,int start,int mid,int end)
{
    int i,j,k;
    vi left,right;

    k = start;
    i = j = 0;

    for(int i=start;i<=mid;++i)
        left.push_back(v[i]);

    for(int j=mid+1;j<=end;++j)
        right.push_back(v[j]);

    while(i < left.size() && j < right.size())
    {
        if(left[i] < right[j])
        {
            v[k++] = left[i++];
        }else
        {
            v[k++] = right[j++];
        }
    }

    while(i < left.size())
    {
        v[k++] = left[i++];
    }

    while(j < right.size())
    {
        v[k++] = right[j++];
    }
}