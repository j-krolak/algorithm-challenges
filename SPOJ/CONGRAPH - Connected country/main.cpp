/*
 * https://www.spoj.com/submit/CONGRAPH/
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 8e5 + 10;

vector<int> cities[MAXN];

bool visited[MAXN];

void DFS(int v)
{
	visited[v] = true;

	for(size_t i = 0; i < cities[v].size(); i++)
	{
		if(!visited[cities[v][i]])
		{
			DFS(cities[v][i]);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;

	int c1, c2;
	while(m--)
	{
		cin >> c1 >> c2;
		cities[c1].push_back(c2);
		cities[c2].push_back(c1);
	}
	
	int ans = 0;

	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			DFS(i);
			ans++;
		}
	}
	ans--;
	cout << ans << "\n";

	return 0;

}
