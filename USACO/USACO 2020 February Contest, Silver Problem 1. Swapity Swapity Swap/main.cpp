#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	freopen("swap.in","r", stdin);
	freopen("swap.out", "w", stdout);

	int n, m, k;

	cin >> n >> k >> m;

	vector<int> cycle;

	for(int i = 0; i <= n; i++)
	{
		cycle.push_back(i);
	}

	vector<pair<int,int>> swaps;

	for(int i = 0; i < k; i++)
	{
		int a,b;
		cin >> a >> b;
		swaps.push_back(make_pair(a,b));
	}

	for(pair<int,int> swap : swaps)
	{
		int d = swap.second -  swap.first + 1;

		for(int i = 0; i < d/2; i++)
		{
			int buff = cycle[swap.first + i];

			cycle[swap.first + i] = cycle[swap.second - i];
			cycle[swap.second - i] = buff;
		}
	}
	
	vector<int> result(n+1,0);

	for(int  i = 1; i <= n; i++)
	{
		if(result[i] != 0)
			continue;

		vector<int> one_cycle;

		int w = i;	
		do
		{
			one_cycle.push_back(w);
			w = cycle[w];
		
		}
		while(w != i);

		for(int j = 1; j <= one_cycle.size(); j++)
		{
			result[one_cycle[j-1]] = one_cycle[(j-1 + m)% one_cycle.size()];
		}
	}
	
	for(int i = 1; i < n+1; i++)
	{
		cout << result[i] << endl;
	}

	return 0;
}
