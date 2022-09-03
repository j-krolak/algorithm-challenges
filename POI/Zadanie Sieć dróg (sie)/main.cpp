#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 200;

int d[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> d[j][i];
		}
	}

	vector<pair<int, int>> ans;


	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			int len = d[i][j];
			bool t = true;
			for(int k = 0; k < n; k++)
			{
				if(!t)
					break;
				if(k == i || k == j)
					continue;

				if(d[i][k] + d[j][k] == len)
				{
					t = false;
				}
			}

			if(t)
				ans.push_back({i,j});
		}
	
	}

	sort(ans.begin(), ans.end());

	for(size_t i  = 0; i < ans.size(); i++)
	{
		cout << ans[i].first+1 << " " << ans[i].second+1<<"\n";
	}
	return 0;
}
