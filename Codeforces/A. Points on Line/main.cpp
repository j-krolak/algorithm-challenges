#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int points[MAXN];

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,d;

	cin >> n >> d;

	for(int i = 0; i < n; i++)
	{
		cin>>points[i];
	}

	long long ans = 0;

	for(long long i = 0, j = 0; i < n; i++)
	{
		while(points[i] - points[j] > d)
			j++;
		ans += (i-j)*(i-j-1)/2;
	}

	cout << ans << "\n";

	return 0;
}
