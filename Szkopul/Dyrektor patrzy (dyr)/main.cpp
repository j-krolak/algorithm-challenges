/*
 * Link: https://szkopul.edu.pl/problemset/problem/NeHsbwV_Rok4bVgn9LjDoZR9/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e5 + 10;

vector<int> G[MAXN];
int pre[MAXN];
int post[MAXN];

int c = 1;

void BFS(int v, int p)
{
	pre[v] = c;
	c++;

	for(size_t i = 0; i < G[v].size(); i++)
	{
		int u = G[v][i];
		if(u != p)
			BFS(u,v);
	}

	post[v] = c;
	c++;
}

int is_ancestor(int a, int b)
{
	return (pre[a] < pre[b]) && (post[a] > post[b]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q, v1;
	cin >> n >> q;
	
	for(int i = 2; i <= n; i++)
	{
		cin >> v1;
		G[v1].push_back(i);
		G[i].push_back(v1);
	}

	BFS(1,1);
	int a,b,c;
	while(q--)
	{
		cin >> a >> b >> c;
		bool ca = is_ancestor(c, a);
		bool cb = is_ancestor(c, b);

		if(ca && cb)
			cout << "Dyrektor patrzy";
		else if(ca)
			cout << "Tylko B";
		else if(cb)
			cout << "Tylko A";
		else
			cout << "Droga wolna";
		cout << "\n";
	}

	return 0;
}
