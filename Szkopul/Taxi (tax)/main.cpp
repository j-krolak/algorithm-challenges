/*
 * Link: https://szkopul.edu.pl/problemset/problem/tax/site/?key=statement 
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e5+10;

vector<int> G[MAXN];
int pre[MAXN];
int post[MAXN];
int c = 1;

void DFS(int v, int p)
{
	pre[v] = c;
	c++;

	for(size_t i = 0; i < G[v].size(); i++)
	{
		int u = G[v][i];

		if(u != p)
			DFS(u, v);
	}
	
	post[v] = c;
	c++;
}

bool is_ancestor(int a, int b)
{
	return (pre[a] <= pre[b]) && (post[a] >= post[b]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	int a,b;
	for(int i = 1; i < n; i++)
	{
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	DFS(1,1);
	/*
	 * z - home
	 * x - start
	 * y - end
	 */

	int m, z, x, y;
	cin >> m;

	for(int i = 0; i < m; i++)
	{
		cin >> z >> x >> y;
			
		if(is_ancestor(z,x) && is_ancestor(z,y))
			cout << "TAK\n";
		else
			cout << "NIE\n";
	}

	return 0;
}
