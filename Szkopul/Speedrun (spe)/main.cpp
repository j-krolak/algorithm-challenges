/*
 * Link: https://szkopul.edu.pl/problemset/problem/e0qogVe4A5ivK_pTdUXL39FV/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MAXN = 1e5+10;
constexpr ll MAXA = 1e10;

int G[MAXN];
bool visited[MAXN] = { false };
bool c[MAXN] = { false };


int search(int v)
{
	if(c[v])
		return -1;
	if(visited[v])
		return v;
	visited[v] = true;

	int ans = search(G[v]);
	c[v] = true;
	return ans;
}

ll calc_cycle(int v)
{
	ll ans = v;
	int i = G[v];

	while(i != v)
	{
		ans += i;
		i = G[i];
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> G[i];
	}


	ll ans = MAXA;

	for(int i = 1; i <= n; i++)
	{
		if(c[i])
			continue;
		int v = search(i);
		if(v != -1)
			ans = min(ans, calc_cycle(v));
	}

	cout << ans << "\n";

	return 0;
}
