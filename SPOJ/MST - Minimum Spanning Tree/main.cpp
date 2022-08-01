/*
 * Link: https://www.spoj.com/problems/MST/
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e4 + 20;

int par[MAXN];

int Find(int val);
void Union(int u, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	vector<pair<int, pair<int,int>>> edges;

	for(int i = 0; i < m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;

		edges.push_back({w, {u,v}});
	}
	
	sort(edges.begin(), edges.end());
	
	for(int i = 0; i < MAXN; i++)
		par[i] = i;

	long long ans = 0;

	for(int i = 0; i < edges.size(); i++)
	{
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		if(Find(u) != Find(v))
		{
			Union(u,v);
			ans += edges[i].first;
		}
	}

	cout << ans << "\n";

	return 0;
}


int Find(int val)
{
	if(par[val] != val)
		par[val] = Find(par[val]);
	return par[val];
}

void Union(int u, int v)
{
	par[Find(u)] = Find(v);
}


