#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int liczba_dwu[MAXN];
int prefiks[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	

	int a,b,c;
	
	a = 0;
	while(a <= 1e3)
	{
		b = a;
		c = a*a + b*b;

		while(c < MAXN)
		{
			liczba_dwu[c] = 1;
			b++;
			c = a*a + b*b;
		}
		a++;
	}

	for(int i = 1; i < MAXN; i++)
	{
		prefiks[i] = prefiks[i-1] + liczba_dwu[i];
	}

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int s,e;
		cin >> s >> e;
		cout << prefiks[e] - prefiks[s-1] << "\n";
	}

	return 0;
}
