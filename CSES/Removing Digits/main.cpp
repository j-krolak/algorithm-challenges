/*
 * Link: https://cses.fi/problemset/task/1637/
 */
#include<bits/stdc++.h>

using namespace std;

int max_digit(int x)
{
	int i = x%10;

	while(x > 0)
	{
		i = max(i, x%10);
		x /= 10;
	}

	return i;
}

int main()
{
	int n;
	cin >> n;

	int ans = 0;

	while(n > 0)
	{
		ans++;
		n -= max_digit(n);
	}

	cout << ans << "\n";

	return 0;
}
