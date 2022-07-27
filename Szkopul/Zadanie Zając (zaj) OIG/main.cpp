/*
 * Link: https://szkopul.edu.pl/problemset/problem/wQAk4d4zyJLueWkOPiNq_yD7/site/?key=statement
 */
#include<bits/stdc++.h>

#define fi first
#define sc second

using namespace std;

enum state
{
	e,
	molehill,
	hare,
	den
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	bool field[n][m];
	pair<int, int> hare_pos;
	pair<int, int> den_pos;
	for(int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;

		for(int j = 0; j < m; j++)
		{
			if(tmp[j] == 'x')
				field[i][j] = false;
			else
				field[i][j] = true;

			if(tmp[j] == 'z')
				hare_pos = make_pair(i,j);
			if(tmp[j] == 'n')
				den_pos = make_pair(i,j);
		}
	}

	
	// array for BFS
	int min_moves[n][m];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			min_moves[i][j] = -1;
		}
	}
	
	min_moves[hare_pos.fi][hare_pos.sc] = 0;
	queue<pair<int, int>> Q;
	Q.push(hare_pos);

	while(!Q.empty())
	{
		pair<int, int> tmp = Q.front();
		Q.pop();

		pair<int, int> nei[8] = 
		{
			{tmp.fi+1, tmp.sc+2},
			{tmp.fi+1, tmp.sc-2},
			{tmp.fi-1, tmp.sc+2},
			{tmp.fi-1, tmp.sc-2},
			{tmp.fi+2, tmp.sc+1},
			{tmp.fi+2, tmp.sc-1},
			{tmp.fi-2, tmp.sc+1},
			{tmp.fi-2, tmp.sc-1}
		};


		for(int i = 0; i < 8; i++)
		{
			if(nei[i].fi < 0 || nei[i].fi >= n || nei[i].sc < 0 || nei[i].sc >= m)
				continue;

			if(min_moves[nei[i].fi][nei[i].sc] != -1)
				continue;
			if(!field[nei[i].fi][nei[i].sc])
				continue;

			Q.push(nei[i]);
			min_moves[nei[i].fi][nei[i].sc] = min_moves[tmp.fi][tmp.sc] + 1;
		}
	}

	if(min_moves[den_pos.fi][den_pos.sc] == -1)
	{
		cout << "NIE\n";
	}
	else
	{
		cout << min_moves[den_pos.fi][den_pos.sc] << "\n";
	}

	return 0;
}
