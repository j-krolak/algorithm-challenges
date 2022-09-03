#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 500;

int d[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> d[i][j];
		}
	}

	vector<pair<int, int>> ans;


	for(int i = 1; i <= n; i++)
	{
		for(int j = i+1; j <= n; j++)
		{
			int len = d[i][j];
			bool t = true;
			for(int k = 1; k <= n; k++)
			{
				if(k == i || k == j)
					continue;

				if(d[k][i] + d[k][j] == len)
				{
					t = false;
					break;
				}
			}

			if(t)
				ans.push_back({min(i,j),max(i,j)});
		}
	
	}

	sort(ans.begin(), ans.end());

	for(size_t i  = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second<<"\n";
	}
	return 0;
}
