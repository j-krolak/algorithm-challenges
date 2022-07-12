#include<bits/stdc++.h>

using namespace std;

int cont;
constexpr int MAXN = 1e5 + 7;

int books[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int t;
	cin >> n;
	cin >> t;

	for(int i =0; i < n; i++)
	{
		cin >>  books[i];
	}


	int ans = 0;
	int p =0;
	int k = 0;
	int s = books[0];
	while(k < n && p < n)
	{
		if(s <= t && k < n)
		{
			ans = max(ans, k-p+1);
			k++;
			s += books[k];
		}
		else
		{
			s -= books[p];
			p++;
		}
	}

	cout << ans << "\n";
	
	return 0;
}
