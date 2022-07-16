#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	int ans;
	cin >> ans;

	for(int i = 1; i<n; i++)
	{
		int a;
		cin >> a;
		ans = min(ans,a);
	}

	cout << ans << ".00\n";
}
