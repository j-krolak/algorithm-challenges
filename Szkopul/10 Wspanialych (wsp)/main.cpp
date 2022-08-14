#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int candidats[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> candidats[i];

	for(int i = 0; i < 10; i++)
	{
		for(int j = n-1; j > i; j--)
		{
			if(candidats[j] > candidats[j-1])
				swap(candidats[j], candidats[j-1]);
		}
		cout << candidats[i] << " ";
	}

	return 0;
}
