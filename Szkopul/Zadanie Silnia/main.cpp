#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	if(n >= 5)
		cout << 0 << endl;
	else
	{
		int r = 1;
		for(int i = 1; i <= n; i++)
		{
			r *= i;
		}

		r %= 10;
		cout << r;
	}
	return 0;
}
