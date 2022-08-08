/*
 * Link: https://szkopul.edu.pl/problemset/problem/_GcQdStgudaHcnq9XI3qAVWl/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;
constexpr int MOD = 10000;

int factorial[MAXN] = {1};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for(int i = 1; i < MAXN; i++)
		factorial[i] = (factorial[i-1] * i) % MOD;

	int n;
	cin >> n;

	map<int, int> mp;
	int tmp;

	for(int i = 0; i < n; i++)
	{
		cin >> tmp;

		if(mp.find(tmp) == mp.end())
		{
			mp[tmp] = 1;
		}
		else
		{
			mp[tmp]++;
		}
	}


	map<int, int>::iterator it;

	int ans = 1;
	int len = 0;
	bool less = true;
	for(it = mp.begin(); it != mp.end(); it++)
	{	
		len++;
		if(it->second > 7)
			less = false;
		ans = (ans * factorial[it->second]);

		if(ans > 1000)
			less = false;
		ans %= MOD;
	}
	
	ans = len > 1 ? (2 * ans)%MOD : ans;
	string res = to_string(ans);


	tmp = less ? 0 : 4  - res.size();

	for(int i = 0; i < tmp; i++)
	{
		res = '0' + res;
	}
	
	if(n > 1)
		cout << res << "\n";
	else
		cout << "1\n";

	return 0;
}
