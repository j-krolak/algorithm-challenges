/*
 * Link: https://szkopul.edu.pl/problemset/problem/UJ7ImMeWphKxSOy6HFKT6AOW/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAXN = 1e6 + 10;


int t[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> t[i];

	ll ans = 0;
	ll sum = 0;
	ll j;
	stack<pair<int, int>> s;
	s.push({INT_MAX, 0});
	for(int i = 0; i < n; i++)
	{
		j = 1;

		while(s.top().first < t[i])
		{
			j += s.top().second;
			sum -= (ll)s.top().first * s.top().second;
			s.pop();
		}	
		s.push({t[i], j});
		sum += (ll)t[i]*j;
		ans += sum;
	}

	cout << ans << "\n";

	return  0;
}
