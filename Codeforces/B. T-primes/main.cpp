/*
 * https://codeforces.com/problemset/problem/230/B
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXX = 1e6+10;
bool prime[MAXX] = {true};

void sieve_of_eratosthenes()
{
	for(bool &element : prime)
		element = true;

	for(int i = 2; i * i < MAXX; i++)
	{
		for(int j = i*i; j < MAXX; j += i)
			prime[j] = false;
	}
}

//Binary search version of sqrt
int binary_search(long long a)
{
	long long begin = 0, end = 1e6, mid;

	while(begin < end)
	{
		mid = (begin+end)/2;

		if(mid*mid >= a)
			end = mid;
		else
			begin = mid+1;
	}

	if(end * end != a)
		return -1;
	return end;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	sieve_of_eratosthenes();
	int n;
	cin >> n;
	
	prime[1] = false;

	for(int i = 0; i < n; i++)
	{
		long long x;
		cin >> x;
		
		int ans = binary_search(x);
		if(ans == -1 || !prime[ans])
			cout << "NO\n";
		else
			cout << "YES\n";
			
	}

	return 0;
}
