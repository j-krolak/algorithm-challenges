#include<bits/stdc++.h>

using namespace std;

int calc(int l)
{
	int k = l/3;
	if(l%3 != 0)
		k++;
	return k;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string tmp;
	cin >> tmp;
	
	int ans = 0, l = 0;	
	for(int i = 0; i < n; i++)
	{
		if(tmp[i] == 'W')
		{		
			ans+=calc(l);
			l =0;
		}
		else
		{
			l++;
		}
	}
	
	ans += calc(l);
	
	cout << ans << "\n";

	return 0;
}
