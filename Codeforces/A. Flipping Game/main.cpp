/*
 * Link: https://codeforces.com/problemset/problem/327/A
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e2 + 10;

int a[MAXN];
int pref[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; i++)
	{
		pref[i] = pref[i-1] + a[i];
	}

	int ans = 0;

	for(int i = 1; i <= n; i++)
	{
		int tmp = 0;
		for(int j = i; j <= n; j++)
		{
			if(a[j] == 0)
				tmp++;
			ans = max(ans,pref[i-1] + tmp + pref[n] - pref[j]);
		}
	}

	cout << ans << "\n";

	return 0;
}
