#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

pair<int,int> friends[MAXN];


long long solve(int n, int d)
{
	d--;
	sort(friends, friends+n);
	int e = 0;
	long long ans = 0;
	long long sum = friends[0].second;
	for(int s = 0; s < n; s++)
	{
		while(friends[e].first - friends[s].first <= d)
		{
			ans = max(ans,sum);
			if(e < n-1)
			{
				e++;
				sum += friends[e].second;
			}
			else
			{
				break;
			}
		}

		sum-=friends[s].second;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, d;
	cin >> n >> d;

	for(int i = 0; i < n; i++)
	{
		int m,s;
		cin >> m >> s;
		friends[i] = make_pair(m,s);
	}


	cout << solve(n,d) << "\n";
	return 0;
}
