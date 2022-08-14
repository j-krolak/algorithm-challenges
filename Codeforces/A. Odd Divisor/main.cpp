/*
 * Link: https://codeforces.com/problemset/problem/1475/A
 */
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(ll n)
{
	bool has_an_odd_div = false;
	while(n > 1)
	{
		if(n % 2 != 0)
		{
			has_an_odd_div = true;
			break;
		}
	
		n /= 2;
	}

	if(has_an_odd_div)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	ll n;
	while(t--)
	{
		cin >> n;
		solve(n);
	}

	return 0;
}
