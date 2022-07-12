#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	set<int> x;

	int buffer;
	for(;n>0;n--)
	{
		cin >> buffer;
		x.insert(buffer);
	}

	cout << x.size();
	return 0;
}
