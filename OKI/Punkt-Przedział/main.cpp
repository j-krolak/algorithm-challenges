#include<bits/stdc++.h>

using namespace std;

constexpr int MAXQ = 1<<18;


constexpr int base=1<<17;
int s_tree[2*base];

void insert(int a, int b)
{
	a = base + a;
	s_tree[a] = b;
	a /= 2;
	
	while(a > 0)
	{
		s_tree[a] = max(s_tree[2*a], s_tree[2*a+1]);
		a/=2;
	}
}

int query(int a, int b)
{	
	a = base + a - 1;
	b = base + b + 1;
	int res = 0;
	
	while(a/2 != b/2)
	{
		if(a%2 == 0)
			res = max(res, s_tree[a+1]);
		if(b%2 == 1)
			res = max(res, s_tree[b-1]);

		a/=2;
		b/=2;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q, t, a, b;

	cin >> q;

	for(int i = 0; i < q; i++)
	{
		cin >> t >> a >> b;
		if(t==0)
		{
			insert(a, b);
		}
		else
		{
			cout << query(a, b) << "\n";
		}
	}
	
	return 0;
}
