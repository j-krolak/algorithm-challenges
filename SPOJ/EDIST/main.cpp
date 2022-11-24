#include<bits/stdc++.h>

using namespace std;

void sol()
{
	string a, b;
	cin >> a >> b;
	int dp[a.size()][b.size()];
	
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < b.size(); j++)
		{
			dp[i][j] = 0;
		}
	}
	
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < b.size(); j++)
		{
			dp[i][j] = 0;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	
	while(n--)
		sol();
	
	return 0;
}
