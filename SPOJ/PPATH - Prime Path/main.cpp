/*
 * Link: https://www.spoj.com/problems/PPATH/
 */
#include<bits/stdc++.h>

using namespace std;


const int MAXP = 1e5 + 10;
bool prime[MAXP];

void soe()
{
	for(int i = 0; i < MAXP; i++)
	{
		prime[i] = true;
	}

	for(int i = 2; i * i < MAXP; i++)
	{
		if(!prime[i])
			continue;
		
		for(int j = i * i; j < MAXP; j += i)
			prime[j] = false;
	}

	prime[0] = false;
	prime[1] = false;
}

// a - > XXXX b -> 2 c - > 7 result -> X7XX 
int change(int a, int b, int c)
{
	int result = 0;
	int j = 1;
	for(int i = 1; i <= 4; i++)
	{
		if(i != b)
		{
			result += (a % 10) * j;
			a /= 10;
			j *= 10;
		}
		else
		{
			result += c * j;
			j *= 10;
			a /= 10;
		}

	}

	return result;
}

void BFS_Solve()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	cin >> a >> b;
	if(a == b)
	{
		cout << "0\n";
		return;
	}
	int moves[MAXP];
	for(int i = 0; i < MAXP; i++)
	{
		moves[i] = -1;
	}
	moves[a] = 0;
	queue<int> Q;
	Q.push(a);
	while(!Q.empty())
	{
		a = Q.front();
		Q.pop();

		vector<int> next;

		for(int i = 1; i <= 4; i++)
		{
			for(int j = 0; j <= 9; j++)
			{
				int pr = change(a, i, j);
				if(pr > 1000 && prime[pr])
				{
					next.push_back(pr);
				}
			}
		}

		for(size_t i = 0; i < next.size(); i++)
		{
			if(moves[next[i]] != -1)
				continue;
			Q.push(next[i]);
			moves[next[i]] = moves[a] + 1;
			if(next[i] == b)
			{
				cout << moves[next[i]] << "\n";
				return;
			
			}
		}
	}

	cout << "Impossible\n";
}

int main()
{
	soe();
	int t;
	cin >> t;
	while(t--)
	{
		BFS_Solve();
	}
	return 0;
}
