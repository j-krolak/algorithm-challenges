#include<bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e5 + 10;

int tasma[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int query_q;
	cin >> query_q;
	int n;
	int tas;
	for(int i = 0; i < query_q; i++)
	{
		cin >> n;
		int ans = 0;
		
		for(int j = 1; j <= n; j++)
		{
			cin >> tasma[j];
		}

		int p,k;
		p = 1; k =n;
		int s = tasma[1];
		while(s == tasma[k] && p < k)
		{
			k--;
		}
		ans = k-p;

		p = 1; k = n;
		s = tasma[n];

		while(s == tasma[p] && p < k) 
		{
			p++;
		}

		ans = max(ans, k-p);

		if(ans == 0)
		{
			cout << "BRAK\n";
		}
		else
		{
			cout << ans-- << "\n";
		}

	}
	return 0;
}
