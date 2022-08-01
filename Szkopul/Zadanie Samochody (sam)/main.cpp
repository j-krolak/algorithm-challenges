/*
 * Link: https://szkopul.edu.pl/problemset/problem/LYv3GgRJE475pdAP5SrfSjvW/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	int tmp = 0;
	int dir;

	long long ans = 0;

	for(int i = 0; i < n; i++)
	{
		cin >> dir;

		if(dir == 0)
			tmp++;
		else
			ans += tmp;
	}

	cout << ans << "\n";

	return 0;
}
