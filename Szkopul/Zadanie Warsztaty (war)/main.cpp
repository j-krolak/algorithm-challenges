/*
 * Link: https://szkopul.edu.pl/problemset/problem/75WTu9ZZJlfrT_dO204-8djk/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6+10;

int colors[MAXN];
vector<int> par[MAXN];
int cars[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;


	

	for(int i = 0; i < n; i++)
		cin >> cars[i];
	
	for(int i = 0; i <= n; i++)
	{
		par[cars[i]] = {cars[i]};
	 	colors[cars[i]] = cars[i];
	}

	int a,b, tmp;

	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;

		while(!par[a].empty() && a != b)
		{
			tmp = par[a].back();
			colors[tmp] = b;
			par[b].push_back(tmp);
			par[a].pop_back();
		}
	}


	for(int i = 0; i < n; i++)
	{
		cout << colors[cars[i]] << " ";
	}
	cout << "\n";
	return 0;
}
