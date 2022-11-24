#include<bits/stdc++.h>

using namespace std;

vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	int tmp;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.begin()+n+1, greater<int>());

	int ans = k;
	int c = v[k-1];
	for(int i = k; i < n; i++)
	{
		if(v[i] != c)
		{
			break;
		}

		ans++;
	}

	cout << ans << '\n';

	return 0;
}
