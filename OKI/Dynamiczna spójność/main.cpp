#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6;

int R[MAXN];

int find(int v)
{
	if(R[v] == v)
		return v;
	return R[v] = find(R[v]);
}

void join(int a, int b)
{
	if(find(a) == find(b))
		return;
	
	R[find(a)] = b;
}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for(int i = 0; i < MAXN;i++)
		R[i] = i;
	
	int n, q;
	cin >> n >> q;
	
	for(int i = 0; i < q; i++)
	{
		int t, a, b;
		cin >> t >> a >> b;
		
		if(t == 1)
		{
			join(a,b);
		}
		else
		{
			if(find(a) == find(b))
				cout << "TAK\n";
			else
				cout << "NIE\n";
		}
	}
	
	
	return 0;
}
