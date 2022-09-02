/*
 * Link: https://szkopul.edu.pl/problemset/problem/fIwYfy0zzmVZJJXTShFq2ICC/site/?key=statement 
 */
#include<bits/stdc++.h>

using namespace std;

int n,m;

constexpr int MAXN=183;

bool g[MAXN][MAXN];
int ans[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	queue<pair<int, int>> que;

	for(int i =0; i < n; i++)
	{
		string st;
		cin >> st;
		for(int j = 0; j < m; j++)
		{
		
			if(st[j] == '1')
			{
				g[j][i] = true;
				que.push({j, i});
			}
		}
	}

	int x, y;

	while(!que.empty())
	{
		pair<int, int> curr = que.front();
		que.pop();
		x = curr.first;
		y = curr.second;

		if(x+1<MAXN && g[x+1][y] == false && ans[x+1][y] == 0)
		{
			que.push({x+1, y});
			ans[x+1][y] = ans[x][y] + 1;
		}

		if(x-1>=0 && g[x-1][y] == false && ans[x-1][y] == 0)
		{
			que.push({x-1, y});
			ans[x-1][y] = ans[x][y] + 1;
		}
		
		if(y+1<MAXN && g[x][y+1] == false && ans[x][y+1] == 0)
		{
			que.push({x, y+1});
			ans[x][y+1] = ans[x][y] + 1;
		}

		if(y-1>=0 && g[x][y-1] == false && ans[x][y-1] == 0)
		{
			que.push({x, y-1});
			ans[x][y-1] = ans[x][y] + 1;
		}


	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << ans[j][i] << " ";
		}

		cout << "\n";
	}
	return 0;
}

