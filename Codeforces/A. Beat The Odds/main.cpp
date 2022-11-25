#include <bits/stdc++.h>

using namespace std;

void solve();


constexpr int MAXN = 1e6;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	
	return 0;
}

void solve()
{
	int n;
	cin >> n;
	int ans = 0;
	
	int tmp;
	for(int i = 0;i < n; i++)
	{
		cin >> tmp;
		if(tmp % 2)
			ans++;
		
	}
	
	ans = min(ans, n-ans);
	cout << ans << '\n';
}
