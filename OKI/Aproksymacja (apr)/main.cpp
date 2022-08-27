#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;
constexpr double EPS = 1e-12;

int a[MAXN];

double ans[MAXN];

bool check(double m, int n)
{
	ans[0] = (double)a[0] - m;
	for(int i = 1; i < n; i++)
	{
		ans[i] = max(ans[i-1], (double)a[i]-m);
		if((double)a[i] + m < ans[i-1])
			return false;
	}

	return true;
}

double bs(int n)
{
	double lo = 0, mi, hi = 1e6 + 10;

	while(hi - lo > EPS)
	{
		mi = (hi+lo)/2;
		if(check(mi, n))
			hi = mi;
		else
			lo = mi + EPS;

	}
	check(hi, n);
	return hi;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	cout << fixed << bs(n) << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << fixed  << ans[i] << "\n";
	}
	return 0;
}

