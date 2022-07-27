/*
 * Link: https://www.spoj.com/submit/ELEVTRBL/
 */
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	int floors[f+1];
	for(int i = 0; i <= f; i++)
	{
		floors[i] = -1;
	}	

	queue<int> Q;
	floors[s] = 0;
	Q.push(s);
	while(!Q.empty())
	{
		int next = Q.front();
		Q.pop();

		int nei[2] = 
		{
			next-d,
			next+u
		};

		for(int i = 0; i < 2; i++)
		{
			if(!(nei[i] > 0 && nei[i] <= f))
				continue;
			if(floors[nei[i]] != -1)
				continue;
			floors[nei[i]] = floors[next] + 1;
			Q.push(nei[i]);
		}
	}

	if(floors[g] == -1)
	{
		cout << "use the stairs\n";
	}
	else
	{
		cout << floors[g] << "\n";
	}

	return 0;
}
