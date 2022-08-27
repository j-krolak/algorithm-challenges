#include<bits/stdc++.h>

using namespace std;

constexpr int base = 1<<17;
constexpr int N = 2 * base;
constexpr int MOD = 1e9 + 7;

int s_tree[N];

void insert(int a, int b, long long c)
{
	a = base + a - 1;
	b = base + b + 1;

	while(a/2 != b/2)
	{
		if(a % 2 == 0)
			s_tree[a+1] = ((long long)s_tree[a+1] * c)%MOD;
		if(b % 2 == 1)
			s_tree[b - 1] = ((long long)s_tree[b-1] * c) %MOD;

		a/=2;
		b/=2;
	}
}

long long query(int a)
{
	a = base + a;
	long long res = 1;

	while(a != 0)
	{
		res = (res * (long long)s_tree[a]) %MOD;
		a/=2;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i < N; i++)
		s_tree[i] = 1;

	int q,t , a, b;
	long long c;
	cin >> q;
	
	while(q--)
	{
		cin >> t;

		if( t == 0 )
		{
			cin >> a >> b >> c;
			insert(a, b, c);
		}
		else
		{
			cin >> a;
			cout << query(a) << "\n";
		}

	}

	return 0;
}
