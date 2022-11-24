#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	int n;
	long long sum;
	int ans;
	cin >> t;

	while(t--)
	{
		cin >> n;
		sum = static_cast<long long>(n/2)* static_cast<long long>(n/2+1);

		if(n % 2 != 0)
			sum += static_cast<long long>((n+1)/2);

		ans = sqrt(sum);
		cout << ans << '\n';
	}

	return 0;
}
