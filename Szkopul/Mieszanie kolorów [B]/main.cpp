#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 7;

int tins[MAXN][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, b,e,c;
	/*
	 * n - liczba puszek
	 * m - liczba operacji
	 * b - początek przedziału
	 * e - koniec przedziału
	 * c - kolor
	 */

	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> b >> e >> c;
		c--;
		tins[b][c] += 1;
		tins[e+1][c] += -1;
	}

	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
			tins[i][0] += tins[i-1][0];

			tins[i][1] += tins[i-1][1];

			tins[i][2] += tins[i-1][2];

	}

	for(int i = 1; i <= n; i++)
	{
		
		if(tins[i][0] > 0 && tins[i][1] > 0 && tins[i][2] == 0)
			ans++;
	}

	cout << ans << "\n";


	return 0;
}
