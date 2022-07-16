#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

constexpr int MAXN = 1e5 + 10;

pair<ll, ll> intervals[MAXN];

int pos(int n, int m, ll d)
{
	ll last = -2 * d;
	ll wynik = 0;
	for(int i = 0; i < m; i++)
	{
		while(max(last+d, intervals[i].first) <= intervals[i].second)
		{
			last = max(last+d, intervals[i].first);
			wynik++;
			if(wynik >= (ll)n)
			{
				return 1;
			}
		}
	}

	return 0;
}

ll solve(int n, int m)
{
	ll p = 0, k = (ll)1e18,mid;

	while(p < k)
	{
		mid = (p+k+1)/2;
		if(pos(n,m,mid) == 1)
		{
			p = mid;
		}
		else
		{
			k = mid-1;
		}
	}

	return p;
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out","w",stdout);

	int n,m;

	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		cin >> intervals[i].first >> intervals[i].second;
	}

	sort(intervals, intervals+m);

	cout << solve(n,m) << "\n";

	return 0;
}
