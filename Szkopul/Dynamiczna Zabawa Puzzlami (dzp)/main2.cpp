#include <bits/stdc++.h>

using namespace std;



int ans(int n)
{
	if(n == 1)
		return 1;
	else
	{
		int r = 0;
		
		for(int i = 1; i <  n/2; i++)
		{
			r += ans(i) * ans(n-i);
		}

		int a = (n-2)/3 + 1; 
		if((n-2) % 3 == 1)
		{
			a = pow(2, a-1);
		}
		else
		{
			a = pow(2,a);
		}
		return r + a;
	}
}

int main()
{
	int n;
	cin >> n;
	
	cout << ans(n) << endl;
	return 0;
}
