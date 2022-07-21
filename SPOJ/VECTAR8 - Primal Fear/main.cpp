/*
 * https://www.spoj.com/problems/VECTAR8/
 * TODO: write it to be readable
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;
bool afraidNum[MAXN];
int afraidNumsCount[MAXN];

bool dont_have_zeros(int a)
{
	while(a > 0)
	{
		if(a%10 == 0)
			return false;
		a /=10;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	afraidNum[1] = true;
	for(int i = 2; i * i < MAXN; i++)
	{
		for(int j = i * i; j < MAXN; j += i)
			afraidNum[j] = true;
	}

	int how = 0;
	for(int i = 2; i < 1e6; i++)
	{
		if(!afraidNum[i])
		{	
			int j = 1;
			int tmp;
			bool aN = dont_have_zeros(i);	
			if(aN)
			{
				while(j < i)
				{
					tmp = i % (j*10);
					j *= 10;
					if(afraidNum[tmp])
					{
						aN = false;
						afraidNum[i] = true;
						break;
					}
				}
			}

			if(aN)
			{
				how++;
			}
		}
		afraidNumsCount[i] = how;
	}

	int t;
	cin >> t;
	for(int i =0; i < t; i++)
	{
		int n;
		cin >> n;
		cout << afraidNumsCount[n] << "\n";
	}

	return 0;
}
