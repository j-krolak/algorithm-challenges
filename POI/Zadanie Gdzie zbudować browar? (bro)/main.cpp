#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e4;

typedef long long ll;

ll z[MAXN];
ll d[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; 
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> z[i] >> d[i];
	}
	

	ll p = 0,
	   l = 1, 
	   dp = 0,
	   dl = 0,
	   zp = 0, 
	   zl = 0,
	   cost = 0;


	for(int i = n; i > 1; i--)
	{
		dl += d[i-1];
		zl += z[i-1];

		cost += dl * z[i-1];
	}

	ll ans = cost;
	for(int i = 0; i < n; i++)
	{
		while(dl > dp + d[p])
		{
			cost -= dl * z[l];
			dl -= d[l];
			zl -= z[l];
			l = (l + 1) % n;
			dp += d[p];
			p = (p+1)%n;
			zp += z[p];
			cost += dp * z[p]; 
		}

		ans = min(ans , cost);
		if(i == n - 1)
			break;

		dl += d[i];
		zl += z[i];
		cost += zl * d[i];

		if(zp > 0)
		{
			dp -= d[i];
			cost -= zp * d[i];
			zp -= z[i+1];
		}
		ans = min(ans, cost);
	}
	cout << ans << "\n";

	return 0;
}
