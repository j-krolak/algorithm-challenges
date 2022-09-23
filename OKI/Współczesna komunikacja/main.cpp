#include<bits/stdc++.h>

using namespace std;

constexpr int MAXB = 1<<14;

int occ[MAXB];

int strToBin(string s)
{
	int res = 0;
	
	for(int i = s.size()-1; i >= 0; i--)
	{
		if(s[i] == '1')
		{
			res += 1 << (s.size()-i-1);
		}
	}
	return res;
}

long long newton(long long n)
{
	return (n)*(n-1)/2;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	string tmp;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		occ[strToBin(tmp)]++;
	}
	
	long long ans = 0;
	
	for(int i = 1; i < 1<<(k+1); i++)
	{
		for(int j = i+1; j < 1<<(k+1); j++)
		{
			if(i & j)
			{
				ans += (long long)occ[i] * (long long)occ[j];
			}
		}
	}
	
	for(int i = 1; i < 1<<(k+1); i++)
	{
		ans += newton(occ[i]);		
	}
	
	cout << ans << "\n";
	
	return 0;
}
