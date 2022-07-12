#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	int ans = 1;

	vector<int> watch;
	for(int i = 0; i <n; i++)
	{
		int b;
		cin >> b;
		watch.push_back(b);
	}

	bool t = true;

	for(int i = 1; i < n; i++)
	{
		if(t)
		{
			if(watch[i] < watch[i-1])
			{
				ans++;
				t  = false;
			}
		}
		else
		{

			if(watch[i] > watch[i-1])
			{
				ans++;
				t = true;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
