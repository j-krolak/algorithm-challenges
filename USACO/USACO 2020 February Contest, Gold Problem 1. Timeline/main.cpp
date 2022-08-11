#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

vector<pair<int, int>> G[MAXN];
int edges_c[MAXN];
int s[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("timeline.in", "r", stdin);
	freopen("timeline.out", "w", stdout);

	int n, m, c;
	cin >> n >> m >> c;
	
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	int a,b,x;
	for(int i = 0; i < c; i++)
	{
		cin >> a >> b >> x;
		G[a].push_back({b, x});
		edges_c[b]++;
	}

	stack<int> next;

	for(int i = 1; i <= n; i++)
	{
		if(edges_c[i] == 0)
			next.push(i);
	}

	while(!next.empty())
	{
		int v = next.top();
		next.pop();

		for(pair<int, int> x : G[v])
		{
			edges_c[x.first]--;
			if(edges_c[x.first] == 0)
				next.push(x.first);
			s[x.first] = max(s[x.first], s[v] + x.second);
		}
	}
	
	for(int i = 1; i <= n; i++)
		cout << s[i] << "\n";
	return 0;
}
