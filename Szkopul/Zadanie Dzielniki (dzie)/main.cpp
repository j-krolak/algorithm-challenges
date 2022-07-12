#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	int n;
	cin >> n;

	set<int> dzielniki;

	for(int i = 1; i <= sqrt(n); i++)
	{
		if(n % i != 0)
			continue;

		dzielniki.insert(i);
		dzielniki.insert(n/i);
	}

	for(const int &a : dzielniki)
	{
		cout << a << "\n";
	}
	return 0;
}
