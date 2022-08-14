/*
 * Link: https://szkopul.edu.pl/problemset/problem/au-E9FH96-3U9rCKhcNsD5n9/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 25e4 + 10;

int w[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> w[i] >> w[i];
	
	int ans = 0;
	stack<int> s;

	for(int i = 0; i < n; i++)
	{
		while(!s.empty() && s.top() > w[i])
		{
			s.pop();
		}

		if(!s.empty() && s.top() != w[i])
		{
			ans++;
			s.push(w[i]);
		}
		if(s.empty())
		{
			s.push(w[i]);
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}

