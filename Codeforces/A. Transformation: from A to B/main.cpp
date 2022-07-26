/*
 * Link: https://codeforces.com/problemset/problem/727/A
 */
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;
	vector<int> result;
	
	result.push_back(b);
	while(b > 1)
	{
		if(b == a || b < a)
			break;
		if(b % 2 == 0)
		{
			b /= 2;
			result.push_back(b);
			continue;
		}

		if((b-1) % 10 == 0)
		{
			b--;
			b /= 10;
			result.push_back(b);
			continue;
		}

		break;

	}

	if(a == result[result.size() -1])
	{
		cout << "YES\n" << result.size() << "\n";
		for(int i = result.size()-1; i >= 0; i--)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}
