#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MAXN = 1e5+10;

ll sub[MAXN];
ll pref[MAXN];
int nums[MAXN];

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,c;

	cin >> n >>c;
	
	
	for(int i = 1; i <= n; i++)
	{
		cin >> nums[i];	
	}
	sort(nums+1, nums+n+1);

	for(int i = 2; i <= n; i++)
	{
		sub[i] = nums[i] - nums[i-1];
		pref[i] = pref[i-1] + sub[i];
	}

	int p=1,k=1;
	ll d = 0;
	int ans = 0;
	while(k <= n && p <= n)
	{
		if(d <= (ll)c)
		{	
			ans = max(ans, k-p+1);
			k++;
			d += (k-p) * sub[k];
		}
		else
		{
			p++;
			d-= pref[k] - pref[p-1];
		}
	}
	
	p=1;
	k=1;
	d = 0;
	int num = 1e9+2;
	while(k <= n && p <= n)
	{
		if(d <= (ll)c)
		{	
			if( (k-p+1) == ans)
				num = min(num, nums[k]);
			k++;
			d += (k-p) * sub[k];
		}
		else
		{
			p++;
			d-= pref[k] - pref[p-1];
		}
	}


	cout << ans << " " << num << "\n";
	return 0;
}
