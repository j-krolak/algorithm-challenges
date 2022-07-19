#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5+10;

int nums[MAXN];
int pref[MAXN];
int suf[MAXN];

int GCD(int a, int b)
{
	while(b != 0)
	{
		int tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}

	for(int i = 1; i <= n; i++)
	{
		pref[i] = GCD(nums[i], pref[i-1]);
	}

	for(int i = n; i > 0; i--)
	{
		suf[i] = GCD(nums[i],suf[i+1]);
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans = max(ans, GCD(pref[i-1], suf[i+1]));
	}
	cout << ans << "\n";
	return 0;
}
