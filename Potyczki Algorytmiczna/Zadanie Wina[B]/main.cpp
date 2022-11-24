#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e3 + 10;

int dp[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	int ans = 1e4;
	int val;
	
	for(int i = 1; i <= n; i++)
	{
	
		for(int j = 1; j <= i; j++)
		{
			cin >> val;
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + 1;
			if(i > 1)
				dp[i][j] -= dp[i-2][j-1];
			
			if(dp[i][j] <= k)
				ans = min(ans, val);
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
