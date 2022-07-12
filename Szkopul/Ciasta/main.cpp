#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;


	bool prime_num[n+1];

	for(bool &p : prime_num)
		p = true;

	prime_num[0] = false;
	prime_num[1] = false;

	for(int i = 2; i <= n; i++)
	{
		if(prime_num[i] == false)
			continue;

		for(int j = 2; j <= n/i; j++)
		{
			prime_num[j*i] = false;
		}
	}

	unsigned long long int result = 1;
	for(int i = 2; i <= n; i++)
	{
		if(prime_num[i])
		{
			unsigned long long int a = i;
			unsigned long long int b = 0;

			while(a <= n)
			{
				a *= i;
				b++;
			}
			
			result = result * b;
		}
	}
	
	cout << result%10 << endl;
	return 0;
}
