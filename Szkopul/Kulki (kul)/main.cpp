/*
 * Link: https://szkopul.edu.pl/problemset/problem/kulki/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;

ll quick_pow(ll a, ll b)
{
	if(b == 0)
		return 1;

	ll res = quick_pow(a, b/2);

	res = (res*res)%M;

	if(b % 2 == 0)
		return res;
	return (res * a) % M;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;


		ll ans = quick_pow(n,n-1) - 1;
		ans *= n%M;
		ans %= M;
		cout << ans << "\n";
	}
}
