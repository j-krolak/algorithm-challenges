#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,l;

	cin >> l >> n;
	
	int ans = 0;


	while(l--)
	{
		int a;
		char tmp;

		cin >> a >> tmp;

		if(tmp == 'P')
		{
			ans = max(ans, n - a);
		}
		else
		{
			ans = max(ans, a);
		}
	}
	cout << ans << "\n";
	return 0;
}
