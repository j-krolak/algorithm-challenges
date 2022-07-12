#include <bits/stdc++.h>

using namespace std;


long long max(long long &a , int &b)
{
	return a > b ? a : b;
}

long long min(long long &a, int &b)
{
	return a > b ? b : a;
}

const int MAXN = 1e6 + 10;

long long listki[MAXN];
long long prefiks[MAXN];
long long prefiks_lewo[MAXN];
long long min_prawo[MAXN];

long long max_prawo[MAXN];
long long max_lewo[MAXN];

int n;
long long result;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for(int i = 1; i <=n; i++)
	{
		cin >> listki[i];
		prefiks[i] = prefiks[i-1] + listki[i];
		min_prawo[i] = min(prefiks[i],min_prawo[i-1]);
	}

	for(int i = n;i > 0; i--)
	{
		prefiks_lewo[i] = prefiks_lewo[i+1] + listki[i];
	}

	for(int i = 1; i <=n; i++)
	{
		max_prawo[i] = max(max_prawo[i-1], prefiks[i]);
	}

	for(int i = n; i > 0; i--)
	{
		max_lewo[i] = max(max_lewo[i+1] , prefiks_lewo[i]);
	}

	result = prefiks[1];
	for(int i = 2; i <= n; i++)
	{
		long long b = prefiks[i] - min_prawo[i-1];
		result = max(result,b);
	}

	for(int i = 1; i <=n; i++)
	{
		result  = max(result, prefiks[i]+max_lewo[i+1]);
	}

	for(int i = n; i > 0; i--)
	{
		result = max(result, prefiks_lewo[i] + max_prawo[i-1]);
	}

	
	cout << result << endl;
	return 0;
}
