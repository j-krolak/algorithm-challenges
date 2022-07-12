#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2 * 1e6 + 10;
int n;
int liczba_zapytan;

long long prefiks[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> prefiks[i];

		prefiks[i] += prefiks[i-1];
	}

	cin >> liczba_zapytan;

	for(int i = 0; i < liczba_zapytan; i++)
	{
		int start, koniec;
		cin >> start >> koniec;

		cout << prefiks[koniec] - prefiks[start-1] << endl;
	}

	return 0;
}
