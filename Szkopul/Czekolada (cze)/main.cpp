#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a,b,c,d;
	cin >> a >> b >> c >> d;
	vector<long long> cd, dd;

	for(int i = 1; i <= sqrt(c); i++)
	{
		if(c % i == 0)
		{
			cd.push_back(i);
			cd.push_back(c/i);
		}
	}

	for(int i = 1; i <= sqrt(d); i++)
	{
		if(d%i== 0)
		{
			dd.push_back(i);
			dd.push_back(d/i);
		}
	}

	for(int i = 0; i < cd.size(); i++)
	{
		for(int j = 0; j < dd.size(); j++)
		{
			long long e,f;
			e = cd[i] * dd[j];
			f = c*d / e;

			if( (e <= a && f <= b) || ( e <= b && f <= a))
			{
				cout << "TAK" << endl;
				return 0;
			}
		}
	}

	cout << "NIE" << endl;

	return 0;
}
