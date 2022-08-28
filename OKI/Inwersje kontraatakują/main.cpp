#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1<<17;

int a[MAXN];

pair<int, int> T[MAXN];


constexpr int base = MAXN;
int s_tree[2*base];

void insert(int v)
{
	v = base + v;
	s_tree[v]++;
	v/=2;
	while(v/2!= 0)
	{
		s_tree[v] = s_tree[2*v] + s_tree[2*v+1];
		v/=2;
	}
}


int query(int a, int b)
{
	int ans = 0;
	a = base + a - 1;
	b = base + b + 1;

	while(a/2 != b/2)
	{
		if(a % 2 == 0)
			ans += s_tree[a+1];
		if(b % 2 == 1)
			ans += s_tree[b-1];
		a /= 2;
		b /= 2;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	T[0] = {INT_MIN,0};
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];

		T[i] = {a[i], i};
	}

	sort(T + 1, T + n + 1);

	int x = -1;

	for(int i = 1; i <= n; i++)
	{
		if(T[i-1].first < T[i].first)
			x++;

		a[T[i].second] = x;
	}

	int ans = 0;

	for(int i = 1; i <= n; i++)
	{
		ans += query(a[i] + 1, n-1);
		insert(a[i]);
	}

	cout << ans << "\n";

	return 0;
}
