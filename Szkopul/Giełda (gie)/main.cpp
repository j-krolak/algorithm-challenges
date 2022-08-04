/*
 * Link: https://szkopul.edu.pl/problemset/problem/H5QP-C9e69Klb8r65qXbJXN7/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6+10;
int a[MAXN];
long long dp[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	long long maks = -1e9;
	for(int i = 1; i <= n; i++)
	{
		dp[i] = max(dp[i-1], a[i] - x + maks);
		maks = max(maks, dp[i-1] - a[i]);
	}

	cout << dp[n] << "\n";
	
	return 0;
}
