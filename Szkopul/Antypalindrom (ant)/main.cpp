/*
 * Link: https://szkopul.edu.pl/problemset/problem/3VH5uFD129oOjmWZTioY1ihW/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	long long result = s.size();
	int w = -1;

	for(int i = 1; i < s.size();i++)
	{
		if(s[i] != s[i-1])
		{
			if(i > 1 && s[i-2] != s[i])
			{
				result += i - w - 1;
			}
			else
			{
				result++;
				w = i - 2;
			}
		}
		else
		{
			w = i - 1;
		}
	}

	cout << result << "\n";

	return 0;
}
