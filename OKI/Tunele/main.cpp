#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6;

int R[MAXN];

int find(int v)
{

	if(R[v] == v)
		return v;
		
	return R[v] = find(R[v]);

}

void join(int a, int b)
{
	R[find(a)] = R[b];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for(int i = 0; i < MAXN; i++)
		R[i] = i;

	int n, m, k;
	cin >> n >> m >> k;
	
	vector<pair<int, int>> tunele(m);
	
	for(int i = m-1; i >= 0; i--)
	{
		int a, b;
		cin >> a >> b;
		tunele[i] = {a, b};
	}
	
	int spojne = n;
	int ans = MAXN;
	for(int i = 0; i < m; i++)
	{
		
		if(find(tunele[i].first) != find(tunele[i].second))
			spojne--;
		join(tunele[i].first, tunele[i].second);
		if(spojne == k)
		{
			ans = i;
		}
	}
	
	cout << m - ans << "\n";
	
	
	
	return 0;
}

