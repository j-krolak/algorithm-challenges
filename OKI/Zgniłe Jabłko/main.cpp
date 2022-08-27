#include<bits/stdc++.h>

using namespace std;


int mod(string k, int a)
{
	int res = 0;

	for(int i = 0; i < k.size(); i++)
	{
		res = (res*10 + (int)k[i]-'0') % a;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string n, k;
	cin >> n >> k;

	int m = mod(k, n.size());
	
	for(int i = m; i < n.size(); i++)
	{
		cout << n[i];
	}

	for(int i = 0; i < m; i++)
	{
		cout << n[i];
	}

	cout << "\n";

	return 0;
}
