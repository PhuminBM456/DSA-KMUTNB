#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;

void A(int n,int sum);

int main()
{
	A(9875,0);
	
	return 0;
}

void A(int n,int sum)
{
	// basecase
	if(n / 10 == 0)
	{
		sum += n % 10;
		//cout << sum << endl;
		
		if(sum / 10 != 0)
		{
			A(sum,0);
		}else
		{
			cout << sum;
		}
		
		return;
	}
	
	sum += n % 10;
	
	// recursion
	A(n/10,sum);
}
