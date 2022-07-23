/*
 * https://www.codechef.com/problems/CC005
 */

#include <iostream>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int prime_f[MAXN];

int main()
{
	for(int i = 2; i < MAXN; i++)
	{
		if(prime_f[i] == 0)
		{
			for(int j = i * 2; j < MAXN; j += i)
				prime_f[j] = i;
		}
	}

	for(int i = 2; i < MAXN; i++)
	{
		if(prime_f[i] == 0)
		{
			prime_f[i] = i;
		}
	}

	int t;
	cin >> t;
	while(t--)
	{
		int n, tmp;
		cin >> n;
		
		int prime_count[MAXN] = {0};

		for(int i = 0; i < n;i++)
		{
			cin >> tmp;
			
			prime_count[prime_f[tmp]]++;
		}

		int c = 0, k = 0;

		for(int i = 0; i < MAXN; i++)
		{
			if(prime_count[i] >= c)
			{
				c = prime_count[i];
				k = i;
			}
		}

		cout << k << "\n";

	}

	return 0;
}
