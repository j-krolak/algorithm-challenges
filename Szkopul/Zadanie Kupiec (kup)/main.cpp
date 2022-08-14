/*
 * Link: https://szkopul.edu.pl/problemset/problem/Geba-YXAmWHFnOUgimkYmoUT/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAXN = 1e6 + 10;
ll pref[MAXN];
int cost[MAXN];
int len[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}

	for(int i = 2; i <= n; i++)
	{
		cin >> len[i];
	}

	for(int i = 1; i <= n; i++)
	{
		pref[i] = pref[i-1] + (ll)len[i];
	}	

	for(int i = 1; i <= n; i++)
	{
		pref[i] += cost[i];
	}

	ll min_p = 1e15+10;
	ll ans = 0;
	for(int i = n; i > 0; i--)
	{
		min_p = min(min_p, pref[i]);
		ans = max(ans, pref[i-1] - min_p);
	}
	
	pref[n+1] = 0;
	for(int i = n; i > 0; i--)
	{
		pref[i] = pref[i+1] + (ll)len[i+1];
	}	

	for(int i = 1; i <= n; i++)
	{
		pref[i] += cost[i];
	}

	min_p = 1e15+10;
	for(int i = 1; i <= n; i++)
	{
		min_p = min(min_p, pref[i]);
		ans = max(ans, pref[i+1] - min_p);
	}
	

	cout << ans << "\n";

	return 0;
}
