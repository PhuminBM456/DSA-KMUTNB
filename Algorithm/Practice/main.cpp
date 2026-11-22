#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 1;
    int* count;

    count = &n;

    *count += 1;

    cout << *count;

    return 0;
}