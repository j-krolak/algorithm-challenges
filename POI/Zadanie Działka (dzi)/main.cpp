#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e4;
int ans = 0;
int n;
int dp[MAXN];

void calc()
{
	stack<pair<int, int>> s;
	
	bool isPop = false;
	int k = 0, g = 0, k2, g2;
	
	for(int i = 1; i <= n+1; i++)
	{

		isPop = false;
		if(!s.empty())
		{
			k = s.top().first;
			g = s.top().second;
		}
		
		while(!s.empty() && g >= dp[i])
		{

			ans = max(ans, (i-k+1)*dp[i]);

			k2 = k;
			g2 = g;
			s.pop();
			isPop = true;
			if(!s.empty())	
			{
				k = s.top().first;
				g = s.top().second;
			}
		}
		if(!s.empty()&&dp[i] > g)
		{
			ans = max(ans, g*(i-k+1));
		}
		
		if((s.empty() && dp[i] > 0) || dp[i] > g)
		{
			if(isPop)
			{
				s.push({k2, dp[i]});
				
			}
			else
			{
				s.push({i, dp[i]});
				
			}
		}
	}
}

int main()
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int tmp;
			cin >> tmp;
			
			if(tmp == 0)
				dp[j]++;
			else
				dp[j] = 0;
		}
		
		calc();
	}
	
	cout << ans << "\n";
	
	return 0;
}
