/*
 * Link: https://szkopul.edu.pl/problemset/problem/fYXVXOreVxlXTRoHZJXyXF2l/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e5 + 100;

int width[MAXN];
int roundel[MAXN];
int pref[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, tmp;
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		cin >> tmp;
		width[i] = tmp;
	}

	for(int i = 1; i <= m; i++)
	{
		cin >> tmp;
		roundel[i] = tmp;
	}
	pref[0] = width[1];
	for(int i = 1; i <= n; i++)
	{
		pref[i] = min(width[i], pref[i-1]);
	}
	
	int current = 1;
	for(int i = n; i > 0; i--)
	{
		if(current > m)
		{
			cout << i+1 << "\n";
			return 0;
		}

		if(roundel[current] <= pref[i])
		{
			current++;
		}


	}
	cout << "0\n";
		
	return 0;
}

/*
 * BinarySearch
 *
vector<int> max_width;
int e;
int BS(int value)
{
	int begin = 0, end = e, mid;

	while(begin < end)
	{
		mid = (begin + end + 1)/2;

		if(max_width[mid] >= value)
		{
			begin = mid;
		}
		else
		{
			end = mid - 1;

		}
	}

	return end;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	
	max_width.resize(n);
	int tmp;
	cin >> max_width[0];

	for(int i = 1; i < n; i++)
	{
		cin >> tmp;
		max_width[i] = min(tmp, max_width[i-1]);
	}
	e = n;
	for(int i = 0; i < m; i++)
	{
		cin >> tmp;
		
		int search_v = BS(tmp);
		if(max_width[search_v] < tmp)
		{
			cout << "0";
			return 0;
		}
		e = search_v-1;
	}

	cout << e+2 << "\n";

	return 0;
}
*/
