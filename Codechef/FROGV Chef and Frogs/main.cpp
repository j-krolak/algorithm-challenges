/*
 * Link: https://www.codechef.com/problems/FROGV
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n, k, p;
	cin >> n >> k >> p;
	
	int frogs[n]; int frogs2[n];
	
	for(int i = 0; i < n; i++)
	{
		cin >> frogs[i];
		frogs2[i] = frogs[i];
	}

	sort(frogs, frogs+n);

	dp[0] = frogs[0];
	for(int i = 1; i < n; i++)
	{
		if(frogs[i] - frogs[i-1] <= k)
		{
			dp[i] = dp[i-1];
		}
		else
		{
			dp[i] = frogs[i];
		}
	}


	map<int, int> mp;
	for(int i = 0; i < n; i++)
	{
		mp[frogs[i]] = i;
	}
	
	int a,b;

	for(int i = 0; i < p; i++)
	{
		cin >> a >> b;
		a--;
		b--;
		a = mp[frogs2[a]];
		b = mp[frogs2[b]];

		if(a > b)
			swap(a, b);

		if(dp[b] <= frogs[a])
			cout << "Yes\n";
		else
			cout << "No\n";

	}

	return 0;
}

