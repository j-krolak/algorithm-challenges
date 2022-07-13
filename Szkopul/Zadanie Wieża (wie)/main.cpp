#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e5 + 10;

int stairs_height[MAXN];
int stairs_pref[MAXN];

int n;

int binary_search(int value)
{
	int begin = 0;
	int end = n+1;
	int mid;

	while(begin < end)
	{
		mid = (begin + end)/2;
		if(stairs_height[mid] >= value)
		{
			end = mid;
		}
		else
		{
			begin = mid + 1;
		}
	}
	end--;
	return end;
}

void solve()
{
	int h;
	cin >> h;

	int ind = binary_search(h);
	int ans = stairs_pref[ind];

	cout << ans << " ";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> n >> q;

	int last = 0;
	int cur;
	int c = 1;
	int j = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> cur;
		if(cur > last)
		{
			j++;
			last = cur;
			stairs_height[j] = last;
		}
		stairs_pref[j] = c;
		c++;
	}

	n = j;
	stairs_height[n+1] = 2e9 - 10;
	for(int i = 0; i < q; i++)
	{
		solve();
	}
	
	return 0;
}
