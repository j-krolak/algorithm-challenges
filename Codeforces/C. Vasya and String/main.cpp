#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	string s;
	cin >> n >> k >> s;

	int ans = 0;

	int count_b = s[0] == 'b' ? 1 : 0;
	int j = 0;
	for(int i = 0; i < n; i++)
	{
		while(count_b <= k && j < n)
		{
			ans = max(ans, j-i+1);
			j++;
			if(s[j] == 'b')
				count_b++;

		}

		if(s[i] == 'b')
			count_b--;

		
	}
	count_b = s[0] == 'a' ? 1 : 0;
	j = 0;
	for(int i = 0; i < n; i++)
	{
		while(count_b <= k && j < n)
		{
			ans = max(ans, j-i+1);
			j++;
			if(s[j] == 'a')
				count_b++;

		}

		if(s[i] == 'a')
			count_b--;

		
	}


	cout << ans << "\n";

	return 0;
}
