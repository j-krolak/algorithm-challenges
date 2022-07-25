/*
 * Link: https://codeforces.com/problemset/problem/977/E
 * I used DFS to solve this problem.
 */
#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2 * 1e5 + 10;

vector<int> g[MAXN];

bool visited[MAXN];
bool correct;


void DFS(int v)
{
	visited[v] = true;
	if(g[v].size() != 2)
		correct = false;

	for(size_t i = 0; i < g[v].size(); i++)
	{
		if(visited[g[v][i]])
			continue;
		DFS(g[v][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m;

	cin >> n >> m;

	int v1,v2;
	for(int i = 0; i < m; i++)
	{
		cin >> v1;
		cin >> v2;

		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	int ans = 0;

	for(int i = 1; i <= n; i++)
	{
		correct = true;
		if(!visited[i])
		{
			DFS(i);
			if(correct)
				ans++;
		}

	
	}

	cout << ans << "\n";
	return 0;
}
