#include<bits/stdc++.h>

using namespace std;

constexpr int MAXB = 1e4 + 20;
constexpr int MAXN = 120;

int dp[MAXN][MAXB];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, b;
	cin >> n >> b;

	vector<int> items_w;

	for(int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		items_w.push_back(w);
	}

	vector<int> items_v;

	for(int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		items_v.push_back(v);
	}



	for(int i = 1; i <= b; i++)
	{
		for(int j = 1; j <= n;j++)
		{

			dp[j][i] = dp[j-1][i];
			if(i-items_w[j-1] >= 0)
			{
				dp[j][i] = max(dp[j][i], dp[j-1][i-items_w[j-1]] + items_v[j-1]);
			}
		}
	}
	cout << dp[n][b] << "\n";
	return 0;
}
