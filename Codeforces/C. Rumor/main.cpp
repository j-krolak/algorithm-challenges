/*
 * Link: https://codeforces.com/problemset/problem/893/C`
 */
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;

int price[MAXN];
bool visited[MAXN];
vector<int> g[MAXN];

int DFS(int v)
{
	visited[v] = true;
	int ans = price[v];
	for(size_t i = 0; i < g[v].size(); i++)
	{
		if(!visited[g[v][i]])
		{
			ans = min(ans,DFS(g[v][i]));
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> price[i];
	}

	int c1, c2;
	while(m--)
	{
		cin >> c1 >> c2;
		g[c1].push_back(c2);
		g[c2].push_back(c1);
	}

	long long ans = 0;

	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{
			
			ans += (long long) DFS(i);
		}
	}
	
	cout << ans << "\n";

	return 0;
}
