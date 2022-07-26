/*
 * Link: https://codeforces.com/problemset/problem/771/A
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1.5e5+10;

vector<int> G[MAXN];
bool visited[MAXN];

long long vertices, edges;

void DFS(int v)
{
	visited[v] = true;
	vertices++;
	edges += G[v].size();
	for(size_t i = 0; i < G[v].size(); i++)
	{
		int u = G[v][i];

		if(!visited[u])
		{
			DFS(u);
		}
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
		cin >> v1 >> v2;
		v1--;
		v2--;
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}	
	
	bool is_reasonable = true;
	for(int i = 0; i < n; i++)
	{
		if(visited[i])
			continue;
		edges = 0;
		vertices = 0;
		DFS(i);
		edges /= 2;
		long long q = vertices % 2 == 0 ?  (vertices/2)*(vertices-1) : (vertices-1)/2*(vertices);
		if(edges != q && vertices > 2)
		{
			is_reasonable = false;
		}
	}

	if(is_reasonable)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
