/*
 * Link: https://szkopul.edu.pl/problemset/problem/UU2Uj-barjiONnRxd9aEVoDj/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e3 + 10;

vector<int> visited[MAXN];

int calc(int n)
{
	return (n * (n-1) * (n-2))/6;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, ans;
	cin >> n >> m;

	ans = calc(n);
	int a, b;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;

		ans -= n - visited[a].size() - visited[b].size() - 2;

		visited[a].push_back(b);
		visited[b].push_back(a);
	}
	cout << ans << "\n";
	return 0;
}
