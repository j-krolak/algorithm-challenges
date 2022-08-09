#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

vector<int> G[MAXN];
int s[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		s[v]++;
	}

	vector<int> q;

	for(int i = 1; i <= n; i++)
		if(s[i] == 0)
			q.push_back(i);
	
	vector<int> res;

	while(!q.empty())
	{
		int v = q.back();
		q.pop_back();
		res.push_back(v);

		for(auto u : G[v])
		{
			s[u]--;
			if(s[u] == 0)
				q.push_back(u);
		}
	}

	if(res.size() != n)
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		for(auto u : res)
			cout << u << " ";
		cout << "\n";
	}

	return 0;
}
