#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e5 + 10;
int a[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n; 


	for(int i = 0; i < n; i++)
		cin >> a[i];

	map<int, int> mp;
	
	a[n] = -1;
	int l = 1;
	
	for(int i = 1; i <= n; i++)
	{
		if(a[i] > a[i-1])
			l++;
		else if(l > 1)
		{
			if(mp.find(l) == mp.end())
			{
				mp[l] = 1;
			}
			else
			{
				mp[l] += 1;
			}
			l = 1;
		}
	}


	map<int, int>::iterator it;

	int q;
	cin >> q;
	while(q--)
	{
		int k;
		cin >> k;
		if(k > 1)
		{

			int ans = 0;

			for(it = mp.begin(); it != mp.end(); it++)
			{
				if(it->first >= k)
					ans += it->second * (it->first - k + 1);
			}

			cout << ans << "\n";
		}
		else
		{
			cout << n << "\n";
		}
	}

	return 0;
}
