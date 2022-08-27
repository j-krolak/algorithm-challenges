#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e5 + 10;
constexpr int INF = 1e9-10;

int z[MAXN];

bool check(int a, int n)
{
	int sum = INF;
	int b = a;
	for(int i = 0; i < n; i++)
	{
		if(z[i] > a)
			return false;
		if(sum + z[i] > a)
		{
			sum = 0;
			b--;
		}

		sum += z[i];
		
	}
	return b >= 0;
}

int bs(int n)
{
	int lo = 1, mi, hi = INF;

	while(lo < hi)
	{
		mi = (lo + hi)/2;
		if(!check(mi, n))
			lo = mi + 1;
		else
			hi = mi;
	}

	return hi;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> z[i];

	cout << bs(n) << "\n";
	return 0;
}
