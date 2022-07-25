#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2 * 1e6 +10;

bool cars[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, p, t;
	cin >> n >> m >> p >> t;
	
	int a, b, ind;

	while(p--)
	{
		cin >> a >> b;
		ind = b-a + 1e6;
		cars[ind] = true;
	}

	int ans = 0;

	while(t--)
	{
		cin >> a >> b;
		ind = b-a + 1e6;
		if(!cars[ind])
			ans++;
	}

	cout << ans << "\n";

	return 0;
}
