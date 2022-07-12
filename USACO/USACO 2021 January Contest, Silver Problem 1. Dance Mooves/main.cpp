#include <bits/stdc++.h>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;

	cin >> n >> k;

	int cycle[n+1];
	int result[n+1] = {0};
	vector<pair<int, int>> swaps;
	unordered_set<int> uniq_pos[n+1];
	

	for(int i = 0; i < k; i++)
	{
		int a,b;
		cin >> a >> b;
		swaps.push_back(make_pair(a,b));
	}
	
	for(int i = 1; i <= n; i++)
	{
		cycle[i] = i;
		uniq_pos[i].insert(i);
	}

	for(int i = 0; i < k; i++)
	{
		int from = swaps[i].first;
		int to = swaps[i].second;
		swap(cycle[from], cycle[to]);
		
		uniq_pos[cycle[to]].insert(to);
		uniq_pos[cycle[from]].insert(from);
	}


	for(int i = 1; i <= n; i++)
	{
		if(result[i] != 0)
			continue;

		unordered_set<int> r;
		int next = i;
		vector<int> cows;

		do
		{
			r.insert(uniq_pos[next].begin(), uniq_pos[next].end());
			cows.push_back(next);
			next = cycle[next];
		} while(next != i);

		for(int cow : cows)
		{
			result[cow] = r.size();
		}
	}
	
	for(int i = 1; i <= n; i ++)
	{

		cout << result[i] << endl;
	}

	return 0;
}
