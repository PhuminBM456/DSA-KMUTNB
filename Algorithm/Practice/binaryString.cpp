#include<bits/stdc++.h>
#define sp ' '
using namespace std;
using vi = vector<int>;

void A(string str,int n,int* count);

int main()
{
	int n,a;
    int* count;

	a = 0;
    count = &a;

	cin >> n;

	A("",n,count);

	cout << *count << endl;

	return 0;
}

void A(string str,int n, int* count)
{
	// basecase
	if(n == 0)
	{
		*count += 1;
		return;
	}

	if(str == "")
	{
		// 0
		A(str + "0",n,count);

		// 1
		A(str + "1",n,count);

		return;
	}

	if(str.length() == n)
	{
		//cout << str << sp;
		*count += 1;
		return;
	}

	// recursion
	int len = str.length() - 1;

	if(str[len] == '0')
	{
		// 0
		A(str + "0",n,count);

		// 1
		A(str + "1",n,count);
	}
	else
	{
		// 0
		A(str + "0",n,count);
	}
}