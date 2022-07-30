/*
 * Link: https://codeforces.com/problemset/problem/1167/C
 */
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 40;

vector<int> G[MAXN];
int siz[MAXN];
int gro[MAXN];
int c = 0,n;

int DFS(int x)
{
	if(gro[x])
		return 0;
	gro[x] = c;
	int ans = (x < n ? 1 : 0);
	
	for(auto y: G[x])
		ans += DFS(y);	

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int k,tmp;
		cin >> k;
		for(int j = 0; j < k; j++)
		{
			cin >> tmp;
			tmp--;
			G[tmp].push_back(n+i);
			G[n + i].push_back(tmp);
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(!gro[i])
		{
			c++;
			siz[c] = DFS(i);
		}

		cout << siz[gro[i]] << " ";
	}

	cout << "\n";

	return 0;
}
