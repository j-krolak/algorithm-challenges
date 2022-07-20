#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MAXN = 2e5 + 10;
int points[MAXN];
ll pref[MAXN];

void solve(int n)
{
	ll p;
	cin >> p;

	int begin = 1,end = n,mid;

	while(begin < end)
	{
		mid = (begin+end)/2;

		if(pref[mid] >= p)
		{
			end = mid;
		}
		else
		{
			begin = mid + 1;
		}
	}

	cout << begin << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> points[i];
	}
	sort(points, points+n);
	
	for(int i = 1; i <= n; i++)
	{
		pref[i] = pref[i-1] + points[n-i];
	}

	int qn;
	cin >> qn;

	for(int i = 0; i < qn; i++)
	{
		solve(n);
	}

	return 0;
}
