#include<bits/stdc++.h>

using namespace std;

void sol()
{
	int v, k;
	cin >> v >> k;
	vector<pair<int, int>> G[v+10];
	int D[v+10];
	bool visited[v+10];
	for(int i = 0; i < v+10; i++)
	{
		D[i] = -INT_MAX;
		visited[i] = false;
	}
	
	for(int i = 0; i < k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({b, -c});
	}
	
	int a, b;
	cin >> a >> b;
	
	
	priority_queue<pair<int, int>> que;
	D[a] = 0;
	que.push({0, a});
	while(!que.empty())
	{
		pair<int, int> t = que.top();
		que.pop();
		if(visited[t.second])
			continue;
		visited[t.second] = true;
		
		for(int i = 0; i < G[t.second].size(); i++)
		{
			D[G[t.second][i].first] = max(D[G[t.second][i].first], D[t.second] + G[t.second][i].second);
			if(!visited[G[t.second][i].first])
				que.push({D[G[t.second][i].first], G[t.second][i].first});
		}
	}
	
	if(D[b] == -INT_MAX)
		cout << "NO\n";
	else
		cout << -D[b] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	while(n--)
	{
		sol();		
	}	
	return 0;
}
