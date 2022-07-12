#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long  a,b;
	cin >> a >> b;

	long long ans = min(a*b - 2 *round(a/2) * b , a*b - 2*round(b/2) * a );
	cout << ans << "\n";
	return 0;
}
