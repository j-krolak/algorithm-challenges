#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MAXN = 1e6 + 10;
constexpr int MOD = 1e9 + 33;

bool prime[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(prime, true, sizeof(prime));

	prime[0] = prime[1] = false;
	for(int i = 2; i * i < MAXN; i++)
	{
		if(!prime[i])
			continue;
		for(int j = i * i; j < MAXN; j += i)
			prime[j] = false;
	}

	int n;
	cin >> n;


	ll ans = 1;

	for(int i = 2; i <= n; i++)
	{
		if(prime[i])
		{
			ll j = i;
			int pos = 0;
			while( j <= n)
			{
				pos++;
				j *= i;
			}
			ans = (ans*pos%MOD)%MOD;
		}
	}

	cout << ans << "\n";

	return 0;
}
