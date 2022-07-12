#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

long long x = 1e9 + 7;
unsigned long long p[MAXN];
unsigned long long w[MAXN];
unsigned long long d[MAXN];

int main()
{

	int n;
	cin >> n;
	
	p[1] = 1;
	w[1] = 1;
	d[1] = 1;

	for(int i = 2; i<=n; i++)
	{
		p[i] = (p[i-1] + w[i-1] + d[i-1] )% x;
		w[i] = (p[i-1] + d[i-2] * 2)%x;
		d[i] = (p[i-1] + w[i-1])%x;
	}

	cout << p[n]<< endl;

	return 0;
}
