/*
 * Link: https://oj.uz/problem/submit/eJOI19_rack
 */
#include<bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;

int main()
{
	int n;
	long long k;
	cin >> n >> k;
	k--;
	int v = 1;

	for(int i = 0; i < n; i++)
	{
		if(k % 2 == 0)
			v = (2 * v) % M;
		else
			v = ((2 * v) + 1) % M;

		k /= 2;
	}


	int p2 = 1;

	for(int i = 0; i < n; i++)
	{
		p2 = (p2 * 2) % M;
	}

	cout << (v - (p2 - 1) + M) % M << "\n";
}
