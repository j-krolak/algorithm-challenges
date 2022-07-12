#include <bits/stdc++.h>

using namespace std;


const int MAXN = 1e6 + 10;

int nA[MAXN];
int rA[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	string  buff;
	cin >> buff;
	for(int i = 1; i <= n; i++)
	{
		rA[i] = rA[i-1];

		if(buff[i-1] == 'R')
		{
			rA[i]++;
		}
		else
		{
			nA[i] = 1;
		}
	}

	int qn;
	cin >> qn;

	for(int i = 0; i < qn; i++)
	{
		int a,b;
		int result = 0;

		cin >> a >> b;

		for(int j = a; j <= b; j++)
		{
			if(nA[j] == 1)
			{
				result += rA[j] - rA[a-1];
			}
		}

		cout << result << endl;
	}

	return 0;
}

