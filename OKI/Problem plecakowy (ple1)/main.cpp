#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 200, MAXB = 1e4 + 10;

int dp[MAXB];
int w[MAXN];
int v[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, b;
	cin >> n >> b;


	for(int i = 0; i < n; i++)
		cin >> w[i];

	for(int i = 0; i < n; i++)
		cin >> v[i];

	for(int i = 0; i < n; i++)
	{

		for(int j = b; j > 0; j--)
		{

			if(j - w[i] < 0)
				break;
			dp[j] = max(dp[j-w[i]]+v[i], dp[j]);
		}
	}

	cout << dp[b] << "\n";

	return 0;
}
