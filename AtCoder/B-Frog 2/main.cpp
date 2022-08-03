#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 7;

int dp[MAXN];
int h[MAXN];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	for(int i = 1; i <= n; i++)
		cin >> h[i];

	dp[0] = 1e9;

	for(int i = 2; i <= n; i++)
	{
		dp[i] = 1e9;

		for(int j = 1; j <= k && j < i; j++)
		{
			dp[i] = min(dp[i], dp[i-j] + abs(h[i-j] - h[i]));
		}
	}

	cout << dp[n] << "\n";


	return 0;
}
