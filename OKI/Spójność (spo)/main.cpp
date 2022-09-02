#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> vec;


constexpr int MAXN = 1e6;

bool vis[MAXN];
vector<int> g[MAXN];

int dfs(int v)
{
	int ans = 1;
	vis[v] = true;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(vis[g[v][i]])
			continue;
		
		ans += dfs(g[v][i]);
	}
	
	return ans;
}

bool check(int v, int n)
{
	for(int i = 0; i < MAXN; i++)
	{
		g[i] = {};
	}
	for(int i =0; i < MAXN; i++)
		vis[i] = false;

	for(int i = 0; i<=v; i++)
	{
		pair<int, int> ve = vec[i];
		g[ve.first].push_back(ve.second);
		g[ve.second].push_back(ve.first);
	}
	int a = dfs(0);


	return a == n;
}


void bs(int n, int m)
{
	int lo = 0, mid, hi = m-1;

	while(lo < hi)
	{
		mid = (hi + lo)/2;
		if(check(mid, n))
		{
			hi = mid;
		}
		else
		{
			lo = mid+1;
		}
	}
	
	if(!check(hi, n))
	{
		cout << "NIE ISTNIEJE\n";
	}
	else
	{
		cout << hi+1 << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin >> n >> m;

	int x, y;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		vec.push_back({x, y});
	}


	bs(n, m);

	return 0;
}
