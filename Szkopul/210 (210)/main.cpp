#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n;
	cin >> n;

	if(n == 0)
	{
		cout << "0 0\n";
		return 0;
	}
	int co = 0;
	string res;
	while(n > 0)
	{
		if(n%2 == 0)
		{
			res = "0" + res;
		}
		else
		{
			res = "1" + res;
			co++;
		}

		n /= 2;
	}
	cout << res <<" ";
	res ="";
	while(co > 0)
	{
		if(co % 2 == 0)
		{
			res = "0" + res;
		}
		else
		{
			res = "1" + res;
		}
		co /= 2;
	}
	cout << res << "\n";
	
	return 0;
}
