/*
 * https://szkopul.edu.pl/problemset/problem/nYCgpBEkq_hw9S-QaoEOOKCI/site/?key=statement
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

constexpr ll MAXM = 1e18;
constexpr ll MAXF = 1.26e6; // NWD(1.26e6, 1.26e6+1, 1.26e6+2)

map<ll, pair<int,int>> mp;


ll GCD(ll a, ll b)
{
	ll c;
	while(b != 0)
	{
		c = b;
		b = a % b;
		a = c;
	}

	return a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll current_lcd;
	ll current_gcd;
	int end;

	for(int begin = 1; begin <= MAXF; begin++)
	{
		end = begin + 1;
		current_lcd = (begin/GCD(begin, end)) * end;

		while(1)
		{
			end++;

			current_gcd = GCD(current_lcd, end);
			
			if(current_lcd/current_gcd > MAXM/(ll)end)
				break;
			current_lcd = (current_lcd/current_gcd) * end;

			if(mp.find(current_lcd) == mp.end())
				mp[current_lcd] = make_pair(begin,end);

		}
	}

	int z;
	cin >> z;

	for(int i = 0; i < z; i++)
	{
		ll x;
		cin >> x;
		
		ll sqrt_x = sqrt(x);

		if(sqrt_x * (sqrt_x+1) > x)
		{
			sqrt_x--;
		}

		if(mp.find(x) != mp.end())
			cout << mp[x].first << " " << mp[x].second << "\n";
		else if(sqrt_x * (sqrt_x + 1) == x)
			cout << sqrt_x << " " << sqrt_x + 1 << "\n";
		else
			cout << "NIE\n";

	}

	return 0;
}
