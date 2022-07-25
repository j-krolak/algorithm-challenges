#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int prime_f[MAXN] = {0}; 

void solve()
{
	int n;
	cin >> n;

	int ans = 1;

	map<int, int> p_f;

	while(n > 1)
	{
		p_f[prime_f[n]]++;
		n /= prime_f[n];
	}

	map<int, int>::iterator it;

	for(it = p_f.begin(); it != p_f.end(); it++)
	{
		if( it->second % 2 != 0)
		{
			ans *= it->first;
		}
	}

	cout << ans << "\n"; 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for(int i = 2; i * i < MAXN; i++)
	{
		if(prime_f[i] == 0)
		{
			for(int j = 2*i; j < MAXN; j += i)
			{
				prime_f[j] = i;
			}
		}
	}

	prime_f[0] = 1;
	for(int i = 0; i < MAXN; i++)
	{
		if( prime_f[i] == 0)
			prime_f[i] = i;
	}

	int t;
	cin >> t;

	while(t--)
	{
		solve();
	}

	return 0;
}
