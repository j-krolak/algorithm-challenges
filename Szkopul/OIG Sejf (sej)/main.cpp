/*
 * Link: https://szkopul.edu.pl/problemset/problem/Plha_6BH8_14ZptrZOdschts/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6+10;
int c[MAXN], r[MAXN];

long long calc(int a, int b, int n)
{
	return (long long)(a - 1) * n + b;
}	

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for(int i = 1; i <=n; i++)
		c[i] = r[i] = i;

	char option;
	int a,b;
	while(m--)
	{
		cin >> option >> a >> b;

		switch(option)
		{
			case 'K':
				swap(c[a], c[b]);
				break;
			case 'W':
				swap(r[a], r[b]);
				break;
			case 'P':
				cout << calc(r[a], c[b], n) << "\n";
				break;
		}
	}

	return 0;
}
