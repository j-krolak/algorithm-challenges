#include<bits/stdc++.h>

using namespace std;


int dp[131080][41];
int k;

void calc(int n)
{
	if(n < 1)
	{	
		return;
	}

	for(int i = 2; i <= k; i++)
	{
		for(int j = 0; j < i; j++)
		{
			dp[n][i] = max(dp[n][1] + dp[2*n][i-j-1] + dp[2*n + 1][j], dp[n][i]);
		}
	}
	
	calc(n-1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n >> k;
	k /= 2;
	int a,b;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <  pow(2, i) ; j++ )
		{
			cin >> a >> b;
			int ind = pow(2, i) + j;
			dp[ind][1] = a+b;
		}
	}

	calc(pow(2, n-1));

	cout << dp[1][k] << "\n";
	return 0;
}

