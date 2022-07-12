#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1.5 * 10e5 + 10;
int n,k;
int pref[MAXN];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <=n; i++)
	{
		int h;
		cin >> h;
		pref[i] = pref[i-1] + h;
	}
	
	int result = 1;
	int minHeight = pref[k];

	for(int i = 2; i <= n - k + 1; i++)
	{
		int a = pref[i+k-1] - pref[i-1];

		if(a < minHeight)
		{
			minHeight = a;
			result = i;
		}
	}

	cout << result << "\n";

	return 0;
}
