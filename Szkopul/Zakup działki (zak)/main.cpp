/*
 * URL: https://szkopul.edu.pl/problemset/problem/zak/site/?key=statement
 */

#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2 * 1e5 + 10;

int dis[MAXN];
int n;


int binary_search(int begin, int end, int value)
{
	int mid;

	while(begin < end)
	{
		mid = (end+begin)/2;

		if(dis[mid] >= value)
		{
			end = mid;
		}
		else
		{
			begin = mid + 1;
		}
	}

	return end;
}

void solve()
{
	int a;
	cin >> a;
	int ind = binary_search(1,n, a);
	
	int right = abs(dis[ind] - a);
	int left = abs(dis[ind-1] - a);
	int ans = min(right, left);
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	int q;
	cin >> n >> q;
	dis[0] = -2e9+10;
	dis[n+1] = 2e9-10;
	for(int i = 1; i <= n; i++)
	{
		cin >> dis[i];
	}

	for(int i = 0; i < q; i++)
	{
		solve();
	}

	return 0;
}
