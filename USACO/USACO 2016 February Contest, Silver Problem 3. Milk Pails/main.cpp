/*
 * Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=620
 */
#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int MAXN = 100 + 10;

int x,y;

int dist[MAXN][MAXN];

void BFS(pair<int, int> start)
{
	for(int i = 0; i < MAXN; i++)
	{
		for(int j = 0; j < MAXN; j++)
			dist[i][j] = -1;
	}

	dist[start.fi][start.se] = 0;

	queue<pair<int, int>> Q;
	Q.push(start);

	while(!Q.empty())
	{
		pair<int, int> next = Q.front();
		Q.pop();

		// \x/ -> \y/
		int dXY = min(next.fi, y - next.se);
		// \x/ <- \y/
		int dYX = min(next.se, x - next.fi);

		pair<int, int> nei[6] = 
		{
			{x, next.se},
			{next.fi, y},
			{0, next.se},
			{next.fi, 0},
			{next.fi - dXY, next.se + dXY},
			{next.fi + dYX, next.se - dYX}
		};

		for(int i = 0; i < 6; i++)
		{
			if(dist[nei[i].fi][nei[i].se] != -1)
				continue;
			dist[nei[i].fi][nei[i].se] = dist[next.fi][next.se] + 1;
			Q.push(nei[i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);

	int k, m;
	cin >> x >> y >> k >> m;
	BFS({0, 0});

		
	int ans = 1e9;
	for(int i = 0; i < MAXN; i++)
	{
		for(int j = 0; j < MAXN; j++)
		{
			if(dist[i][j] <= k && dist[i][j] > -1)
			{
				ans = min( abs(m-(i+j)) ,ans);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
