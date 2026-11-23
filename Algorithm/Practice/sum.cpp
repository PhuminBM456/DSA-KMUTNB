#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int sum(vi &v,int start,int end);

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
	
	cout << sum(v,0,v.size()-1);
	
	return 0;
}

int sum(vi &v,int start,int end)
{
	// basecase
	if(start == end)
	{
		return v[start];
	}
	
	// recursion
	int mid = start + (end - start) / 2;
	int left = sum(v,start,mid);
	int right = sum(v,mid+1,end);
	int sum = left+right;
	
	return sum;
}