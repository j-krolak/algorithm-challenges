/*
 * Link: https://szkopul.edu.pl/problemset/problem/mfl/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MAXN = 5e2 + 2;
constexpr ll M = 1e9+ 7;

ll z[MAXN];
int res[MAXN];

ll quick_pow(ll a, ll b)
{
	if(b == 0)
		return 1;

	ll res = quick_pow(a, b/2);
	res = (res * res) % M;
	if(b % 2 != 0)
		res *= a;
	res %= M;
	return res;
}


int main()
{
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> z[i];


	ll Z1, Z2;


	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			Z1 = quick_pow(z[i], z[j]);
			Z2 = quick_pow(z[j], z[i]);
			if(Z1 > Z2)
				res[j]+=2;
			else if(Z2 > Z1)
				res[i]+=2;
			else
			{
				res[i]++;
				res[j]++;
			}	
		}
	}

	pair<int, int> winner = {res[1],1};

	for(int i = 1; i <= n; i++)
	{
		if(winner.first < res[i])
			winner = {res[i], i};
	}

	cout << winner.second << "\n";

	return 0;
}
