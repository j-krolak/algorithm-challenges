#include <bits/stdc++.h>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;

	cin >> q;
	
	for(int i = 0; i < q; i++)
	{
		int n; 
		string a;
		cin >> n >> a;

		int s = 0;
		long long  ans = 0;
		map<int,int> mp;
		mp[0] = 1;
		
		for(int j = 0; j < n; j++)
		{
			s += a[j] - '0' - 1;
			ans += mp[s];
			mp[s]++;
		}	

		cout << ans << "\n";
	}

	return 0;
}
