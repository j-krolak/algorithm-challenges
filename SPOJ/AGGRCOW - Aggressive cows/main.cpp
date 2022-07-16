#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 +10;

int stalls[MAXN];


bool pos(int n, int c, int val)
{
	int res = 1;
	int last = 0;
	for(int i = 1; i < n; i++)
	{
		if(stalls[i] - stalls[last] >= val)
		{
			last = i;
			res++;

			if(res >= c)
				return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while(t > 0)
	{
		int n, c;
		cin >> n >> c;

		for(int i = 0; i < n; i++)
		{
			cin >> stalls[i];
		}
		
		sort(stalls, stalls+n);
		int p = 0, k = 1e9,m;

		while(p < k)
		{
			m = (p+k+1)/2;

			if(pos(n,c,m))
				p = m;
			else
				k = m-1;
		}

		cout << k << "\n";
		t--;
	}

	return 0;
}
