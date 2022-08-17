/*
 * Link: https://szkopul.edu.pl/problemset/problem/pandemia_wirusa/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;
int virus[MAXN];

void solve();


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> k;
	
	while(k--)
		solve();

	return 0;
}

void solve()
{
	int n;
	cin >> n;
	
	int ansP = 0;
	int ansL = 0;

	string model;
	cin >> model;
	virus[0] = 1;
	virus[n+1] = 2;
	for(int i = 0; i < model.size(); i++)
	{
		switch(model[i])
		{
			case 'L':
				ansL++;
				virus[i+1] = 1;
				break;
			case 'P':
				ansP++;
				virus[i+1] = 2;
				break;
			default:
				virus[i+1] = 0;
				break;

		}
	}
	int i = 0, j = 1;
	while( i <= n && j <= n+1)
	{
		while( virus[j] == 0 )
		{
			j++;
		}
		
		if(virus[i] == 2 && virus[j] == 1)
		{
			ansP += (j-i-1)/2;
			ansL += (j-i-1)/2;
		}
		else if(virus[i] == 2)
		{
			ansP += (j-i-1);
		}
		else if(virus[j] == 1)
		{
			ansL += (j-i-1);
		}

		i = j;
		j = i + 1;
	}

	printf("%d %d %d\n", ansL, ansP, n-ansL-ansP);

}
