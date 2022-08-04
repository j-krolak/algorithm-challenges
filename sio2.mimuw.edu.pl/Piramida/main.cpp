/*
 * Link: https://sio2.mimuw.edu.pl/c/zwo20/p/pir/
 */

#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

bool trap[MAXN];

int dp[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	string seq;
	cin >> n >> k >> seq;	
	for(int i = 0; i < n; i++)
	{
		if(seq[i] == '0')
			trap[i] = true;
	}

	dp[0] = 1;
	for(int i = 1; i < n; i++)
	{
		if(trap[i])
			continue;

		for(int j = i - 1; j >= 0 && j >= i - 6; j--)
		{
			dp[i] += dp[j];
		}

		dp[i] %= k;

	}

	cout << dp[n-1] << "\n";

	return 0;
}
