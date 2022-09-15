#include<bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'000'007;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	vector<char> chars;
	map<char, int> cti;
	int ind = 0;
	for(int i = 0; i < n; i++)
	{
		if(cti.find(s[i]) == cti.end())
		{
			chars.push_back(s[i]);
			cti[s[i]] = ind;
			ind++;
		}
	}
	
	vector<int> v(ind,0);
	vector<int> pref[n+10];
	
	pref[0] = v;
	for(int i = 1; i <=n ; i++)
	{
		pref[i] = pref[i-1];
		pref[i][cti[s[i-1]]]++;
	}
	
	int ans = 0;
	vector<int> px[n+10];
	map<vector<int>, int> mp;
	mp[v] = 1;
	for(int i = 1; i <= n; i++)
	{
		px[i] = v;
		for(int j = 1; j < ind; j++)
		{
			px[i][j] = pref[i][0] - pref[i][j];
		}
		
		ans = (ans + mp[px[i]]) % MOD;
		if(mp.find(px[i]) == mp.end())
			mp[px[i]] = 0;
		mp[px[i]]++;
	}
	
	cout << ans << "\n";
		
	return 0;
}
