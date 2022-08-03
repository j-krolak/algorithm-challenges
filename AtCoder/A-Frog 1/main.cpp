#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int dp[MAXN];
int h[MAXN];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> h[i];

	dp[0] = 1e9;

	for(int i = 2; i <= n; i++)
		dp[i] = min( dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]) );

	cout << dp[n] << "\n";

	return 0;
}
