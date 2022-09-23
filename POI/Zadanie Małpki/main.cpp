#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2* 1e5 + 10;

int mon[MAXN][2];
int ans[MAXN];

vector<int> G[MAXN];

vector<pair<int, int>> toDel;

int R[MAXN];

int find(int v)
{
	if(R[v] == v)
		return v;
	return R[v] = find(R[v]);
}

void join(int a, int b)
{
	if(find(a) == find(b))
		return;
	R[find(a)] = b;
}

void DFS(int v, int t)
{
	if(ans[v] != -1)
		return;
	ans[v] = t;
	for(int i = 0; i < G[v].size(); i++)
	{
		DFS(G[v][i], t);
	}

}

void remS(int ind,int val)
{
	vector<int> tD;
	for(int i = 0; i < G[ind].size(); i++)
	{
		if(G[ind][i] == val)
			tD.push_back(i);
	}
	
	for(int i = tD.size()-1; i >= 0; i--)
	{
		G[ind].erase(G[ind].begin()+ tD[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for(int i = 0; i < MAXN; i++)
	{
		ans[i] = -1;
		R[i] = i;
		mon[i][0] = -1;
		mon[i][1] = -1;
	}
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
	{
		int l,r;
		cin >> l >> r;
		
		if(l != -1)
		{
			mon[i][0] = l;
			if(find( G[i].begin(), G[i].end(), l) == G[i].end())
			{
				G[i].push_back(l);
				G[l].push_back(i);
			}
		}
		
		if(r != -1)
		{
			mon[i][1] = r;
			if(find( G[i].begin(), G[i].end(), r) == G[i].end())
			{
				G[i].push_back(r);
				G[r].push_back(i);
			}
		}
	}
	for(int i = 0; i < m; i++)
	{
		int c, d;
		cin >> c >> d;
		
		d = d - 1;
		int a = mon[c][d];
		toDel.push_back({c, a});
		
		remS(c, a);
		remS(a, c);
	}
	
		
	for(int i = 1; i <= n; i++)
	{
		
		for(int j = 0; j < G[i].size(); j++)
		{
			
			join(i, G[i][j]);
		}
	}	
	DFS(1, -2);
	for(int t = m-1; t >= 0; t--)
	{
		int a = toDel[t].first;
		int b = toDel[t].second;
		
		join(a, b);
		
		if(find(1) == find(a))
		{
			DFS(a, t);
		}
		
		if(find(1) == find(b))
		{
			DFS(b, t);
		}
		if(find( G[a].begin(), G[a].end(), b) == G[a].end())
		{
			G[a].push_back(b);
			G[b].push_back(a);
		}
	}
		
	for(int i = 1; i <= n; i++)
	{
		if(ans[i] == -2)
			cout << "-1\n";
		else
			cout << ans[i] << "\n";
	}
	return 0;
}





















