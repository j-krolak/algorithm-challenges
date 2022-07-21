/*
 * https://codeforces.com/problemset/problem/776/B
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;
bool prime[MAXN];

void sieve_of_eratosthenes()
{
	for(bool &element : prime)
		element = true;

	for(int i = 2; i * i < MAXN; i++)
	{
		for(int j = i*i; j < MAXN; j += i)
			prime[j] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	sieve_of_eratosthenes();
	int n;
	cin  >> n;

	if(n > 2)
		cout << "2\n";
	else
		cout << "1\n";

	for(int i = 2; i <=n+1; i++)
	{
		if(prime[i])
			cout << "1 ";
		else
			cout << "2 ";
	}
	return 0;
}
