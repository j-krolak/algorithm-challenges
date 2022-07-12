#include <bits/stdc++.h>
#include "dna.h"
using namespace std;

const int MAXN = 1e5 + 10;

int slowo1[MAXN];
int slowo2[MAXN];
int perm[MAXN][3][3];
int n;

void init(string a, string b)
{
	n = a.length();
	for(int i = 0; i < n;i++)
	{
		switch(a[i])
		{
			case 'A':
				slowo1[i] = 0;
				break;
			case 'T':
				slowo1[i] = 1;
				break;
			case 'C':
				slowo1[i] = 2;
				break;
		}

		switch(b[i])
		{
			case 'A':
				slowo2[i] = 0;
				break;
			case 'T':
				slowo2[i] = 1;
				break;
			case 'C':
				slowo2[i] = 2;
				break;
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				perm[i][j][k] = perm[i-1][j][k];
				
			}
		}

		perm[i][slowo1[i-1]][slowo2[i-1]] += 1;
	}

}

int get_distance(int x, int y)
{
	y++;
	int AT = perm[y][0][1] - perm[x][0][1];
	int TA = perm[y][1][0] - perm[x][1][0];
	int TC = perm[y][1][2] - perm[x][1][2];
	int CT = perm[y][2][1] - perm[x][2][1];
	int AC = perm[y][0][2] - perm[x][0][2];
	int CA = perm[y][2][0] - perm[x][2][0];

	if( (AT + AC == TA + CA) && (TA + TC == AT + CT))
	{
		int r = abs(TC - CT) * 2 + min(AT,TA) + min(TC,CT) + min(CA,AC);
		return r;

	}
	else
	{
		return -1;
	}
}

