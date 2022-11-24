#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int ans[MAXN];

vector<int> G[MAXN];


void DFS(int v)
{
	for(int i = 0; i < G[v].size(); i++)
	{
		if(ans[G[v][i]] != 0)
			continue;
			
		ans[G[v][i]] = ans[v] == 1 ? 2 : 1;
		DFS(G[v][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{
		int tmp1, tmp2;
		
		cin >> tmp1 >> tmp2;
		G[tmp1].push_back(tmp2);
		G[tmp2].push_back(tmp1);
	}
	
	
	
	for(int i = 1; i <= n; i++)
	{
		if(ans[i] != 0)
			continue;
		if(G[i].size() == 0)
		{
			cout << "NIE\n";
			return 0;
		}
		ans[i] = 1;
		DFS(i);
	}
	
	cout << "TAK\n";
	for(int i = 1; i <= n; i++)
	{
		if(ans[i] == 1)
		{
			cout << "K\n";
		}
		else
		{
			cout << "S\n";
		}
	}
	
	
	
	return 0;
}

