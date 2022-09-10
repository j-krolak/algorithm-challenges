#include<bits/stdc++.h>

using namespace std;

constexpr int K = 4;
constexpr int MAX = 38;
constexpr int mod = 1e6;
int t[K];
int mem[K][K][MAX+2][MAX+2][MAX+2];
int nmem[K][K][MAX+2][MAX+2][MAX+2];

bool safe(int a, int b, int c)
{
	return !( (a/2 == b/2 && b/2 == c/2) || (a%2 == b%2 && b%2 == c%2) );
}

int calc()
{
	if(t[0] + t[1] + t[2] + t[3] == 1)
		return 1;

	for(int i = 0; i < K; i++)
		for(int j = 0; j < K; j++)
			mem[i][j][(i==0) + (j==0)][(i==1) + (j==1)][(i==2) + (j == 2)]++;

	for(int len = 2; len < t[0] + t[1] + t[2] + t[3]; len++)
	{
		memset(nmem, 0, sizeof(nmem));
		for(int i = 0; i < K; i++)
		{
			for(int j = 0; j < K; j++)
			{
				for(int a = 0; a <= t[0]; a++)
				{
					for(int b = 0; b <= t[1]; b++)
					{
						for(int c = 0; c <= t[2]; c++)
						{
							if(mem[i][j][a][b][c])
							{
								int d = len - a - b - c;
								if(d > t[3])
									continue;

								for(int typ = 0; typ  < K; typ++)
								{
									if(safe(typ, i, j))
									{
											nmem[typ][i][a + (typ == 0)][b + (typ == 1)][c + (typ == 2)] += mem[i][j][a][b][c];
											nmem[typ][i][a + (typ == 0)][b + (typ == 1)][c + (typ == 2)] %= mod;
									}
								}
							}
						}
					}
				}
			}
		}
		memcpy(mem, nmem, sizeof(mem));
	}
	int ans = 0;

	for(int i = 0; i < K; i++)
	{
		for(int j = 0; j < K; j++)
		{
			ans = (ans +  mem[i][j][t[0]][t[1]][t[2]]) % mod;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t[0] >> t[1] >> t[2] >> t[3];

	cout << calc() << "\n";

	return 0;
}
