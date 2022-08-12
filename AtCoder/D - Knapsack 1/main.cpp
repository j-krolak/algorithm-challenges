/*
 * Link: https://atcoder.jp/contests/dp/tasks/dp_d
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;
long long dp[MAXN];

int main()
{
	int n, W, w, v;
	cin >> n >> W;

	for(int i = 0; i < n; i++)
	{
		cin >> w >> v;

		for(int j = W; j >= w; j--)
		{
			dp[j] = max(dp[j], dp[j-w] + v);
		}
	}

	cout << dp[W] << "\n";

	return 0;
}
