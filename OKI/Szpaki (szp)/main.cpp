#include<bits/stdc++.h>

using namespace std;

constexpr int base = 1 << 17;
long long s_tree[2*base];

int q;
long long k;

void insert(int a, int b, long long x)
{
	a = base + a - 1;
	b = base + b + 1;

	while(a/2 != b/2)
	{
		if(a%2 == 0)
		{
			s_tree[a+1] = (s_tree[a+1] * x)%k;
		}

		if(b%2 == 1)
		{
			s_tree[b-1] = (s_tree[b-1] * x)%k;
		}

		a /= 2;
		b /= 2;
	}
}

long long query(int a)
{
	a = base + a;
	long long res = 1;
	while(a != 0)
	{
		res = (res * s_tree[a])%k;
		a /= 2;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i < 2*base; i++)
		s_tree[i] = 1;
	cin >> q >> k;
	
	char l;

	int a, b;
	long long x;
	for(int i = 0; i < q; i++)
	{
		cin >> l;

		if(l == 'N')
		{
			cin >> a >> b >> x;

			insert(a, b, x%k);
		}
		else
		{
			cin >> a;

			if(query(a) == 0)
			{
				cout << "TAK\n";
			}
			else
			{
				cout << "NIE\n";
			}
		}
	}

	return 0;
}
