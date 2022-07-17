#include<bits/stdc++.h>

using namespace std;

constexpr int MAXM = 2e5 + 10;
int moves[MAXM];

bool possible(int n, int k, int a, int lastM)
{
	bool field[n+1];
	for(bool &a : field)
		a = false;

	for(int i = 1; i <= lastM; i++)
	{
		field[moves[i]] = true;
	}

	int ships = 0;
	int lengthShip = 0;
	for(int i = 1; i <= n; i++)
	{
		if(field[i])
		{
			lengthShip = 0;
		}
		else
		{
			lengthShip++;
			if(lengthShip >= a)
			{
				i++;
				lengthShip = 0;
				ships++;
			}
		}

		if(ships >= k)
			return true;

	}

	return false;
}


int binary_search(int n, int k, int a, int m)
{
	if(possible(n,k,a,m))
		return -1;

	int start = 1, end = n, mid;

	while(start < end)
	{
		mid = (start + end) /2;

		if(possible(n,k,a,mid))
			start = mid+1;
		else
			end = mid;
	}

	return end;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, a, m;
	cin >> n >> k >> a >> m;

	for(int i = 1; i <= m; i++)
	{
		cin >> moves[i];
	}
	
	cout << binary_search(n,k,a,m) << "\n";

	return 0;
}
