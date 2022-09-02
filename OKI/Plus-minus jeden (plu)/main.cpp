#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6;

vector< pair<int, int> > g[MAXN];	


vector<int> euler_cycle;
int it[MAXN];
bool vis[MAXN];

vector<pair<int, int>> inp;

void eul(int v)
{
	int w;
	int ind;
	for(; it[v] < g[v].size(); it[v]++)
	{
		w = g[v][it[v]].first; 
		ind = g[v][it[v]].second;
		if(vis[ind])
			continue;
		vis[ind] = true;
		eul(w);
	}

	euler_cycle.push_back(v);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	
	int x,y;
	for(int i = 0; i < k; i++)
	{
		cin >> x >> y;
		inp.push_back({x, n+y});
		g[n+y].push_back({x, i});
		g[x].push_back({n + y, i});
	}

	for(int i = 0; i < MAXN; i++)
	{
		if(g[i].size() % 2 == 1)
		{
			cout << "NIE\n";
			return 0;
		}
	}
	cout << "TAK\n";
	eul(x);
	map<pair<int, int>, int> mp;
	for(int i = 0; i < euler_cycle.size(); i++)
	{
		x = euler_cycle[i];
		y = euler_cycle[i+1];

		if(x > n)
		{
			mp[make_pair(y, x)] = 1;
		}
		else
		{
			mp[make_pair(x, y)] = -1;
		}
	}


	for(int i = 0; i < inp.size(); i++)
	{
		cout << mp[inp[i]] << "\n";
	}


	


	return 0;
}
